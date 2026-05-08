#include "objects/triggerZone.h"
#include "objects/entity.h"
#include <algorithm>
using std::find;

TriggerZone::TriggerZone(int width, int height, int x, int y, bool single, vector<Entity *> observedEntities, function<void()> func)
  : Box(width, height, x, y), single(single), func(func) {
    for (int i=0; i<observedEntities.size(); i++) {
      this->observedEntities.push_back(observedEntities[i]);
    }
  }

void TriggerZone::runFunc(Entity *ent) {
this->func();
if (this->single)
  this->stopObservingEntity(ent);
else 
  this->entitiesIn.push_back(ent);
}

void TriggerZone::checkTrigger() {
  for (int i=0; i<this->observedEntities.size(); i++) {
    Entity *e = this->observedEntities[i];
    if (
      (this->getTop() < e->getBottom() && this->getBottom() > e->getTop()) &&
      (this->getLeft() < e->getRight() && this->getRight() > e->getLeft())
    ) {
      if (find(this->entitiesIn.begin(), this->entitiesIn.end(), e) == this->entitiesIn.end())
        this->runFunc(e);
    } else {
      this->entityLeave(e);
    }
  }
  
}

void TriggerZone::observeEntity(Entity *ent) {
  if (find(this->observedEntities.begin(), this->observedEntities.end(), ent) == this->observedEntities.end())
    this->observedEntities.push_back(ent);
}
void TriggerZone::stopObservingEntity(Entity *ent) {
  auto idx = find(this->observedEntities.begin(), this->observedEntities.end(), ent);
  if (idx != this->observedEntities.end())
    this->observedEntities.erase(idx);
}

void TriggerZone::entityEnter(Entity *ent) {
  auto idx = find(this->entitiesIn.begin(), this->entitiesIn.end(), ent);
  if (idx == this->entitiesIn.end())
    this->entitiesIn.push_back(ent);
}
void TriggerZone::entityLeave(Entity *ent) {
  auto idx = find(this->entitiesIn.begin(), this->entitiesIn.end(), ent);
  if (idx != this->entitiesIn.end())
    this->entitiesIn.erase(idx);
}