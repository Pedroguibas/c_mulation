#include "objects/triggerZone.h"
#include "objects/entity.h"
#include <algorithm>
using std::find;

template <typename T>
TriggerZone<T>::TriggerZone(int width, int height, int x, int y, bool single, vector<T *> observedEntities, function<void(T *ent)> func)
  : Box(width, height, x, y), single(single), func(func) {
    for (int i=0; i<observedEntities.size(); i++) {
      this->observedEntities.push_back(observedEntities[i]);
    }
  }

template <typename T>
void TriggerZone<T>::runFunc(T *ent) {
this->func(ent);
if (this->single)
  this->stopObservingEntity(ent);
else 
  this->entitiesIn.push_back(ent);
}

template <typename T>
void TriggerZone<T>::checkTrigger() {
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

template <typename T>
void TriggerZone<T>::observeEntity(T *ent) {
  if (find(this->observedEntities.begin(), this->observedEntities.end(), ent) == this->observedEntities.end())
    this->observedEntities.push_back(ent);
}
template <typename T>
void TriggerZone<T>::stopObservingEntity(T *ent) {
  auto idx = find(this->observedEntities.begin(), this->observedEntities.end(), ent);
  if (idx != this->observedEntities.end())
    this->observedEntities.erase(idx);
}

template <typename T>
void TriggerZone<T>::entityEnter(T *ent) {
  auto idx = find(this->entitiesIn.begin(), this->entitiesIn.end(), ent);
  if (idx == this->entitiesIn.end())
    this->entitiesIn.push_back(ent);
}

template <typename T>
void TriggerZone<T>::entityLeave(T *ent) {
  auto idx = find(this->entitiesIn.begin(), this->entitiesIn.end(), ent);
  if (idx != this->entitiesIn.end())
    this->entitiesIn.erase(idx);
}