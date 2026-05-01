#include "game/gameController.h"

GameController::GameController(vector<Object *> &objects, vector<HitboxObject *> &hitboxObjects, vector<Entity *> &entities)
    : objects(objects), hitboxObjects(hitboxObjects), entities(entities) {}

GameController::GameController(vector<Object *> &objects, vector<HitboxObject *> &hitboxObjects, vector<Entity *> &entities, float g)
    : objects(objects), hitboxObjects(hitboxObjects), entities(entities) {
  this->gravity = g;
}

void GameController::update(float timespan) {
  for (int i = 0; i < entities.size(); i++) {
    Entity *e = entities[i];
    e->setSpeedY(e->getSpeedY() + this->gravity * timespan);
    e->update(timespan);
  }
}

void GameController::checkCollisions() {
  for (int i = 0; i < entities.size(); i++) {
    for (int j = 0; j < hitboxObjects.size(); j++) {
      if (entities[i] == hitboxObjects[j])
        continue;
      entities[i]->collide(*hitboxObjects[j]);
    }
  }
}

void GameController::loopTick() {
  float timespan = min(this->getTickTimespan(), 0.016f);
  this->update(timespan);
  this->checkCollisions();
}

void GameController::setLastTick() {
  this->lastTick = steady_clock::now();
}

float GameController::getLastTick() {
  return duration<float>(this->lastTick.time_since_epoch()).count();
}

float GameController::getTickTimespan() {
  auto now = steady_clock::now();
  duration<float> span = now - this->lastTick;
  this->lastTick = now;
  return span.count();
}