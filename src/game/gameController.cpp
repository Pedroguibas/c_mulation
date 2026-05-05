#include "game/gameController.h"
#include "game/camera.h"
#include "objects/boundry.h"

GameController::GameController(vector<Object *> &objects, vector<HitboxObject *> &hitboxObjects, vector<Entity *> &entities, Camera *cam, Boundry *boundry)
    : objects(objects), hitboxObjects(hitboxObjects), entities(entities), cam(cam), boundry(boundry) {}

GameController::GameController(vector<Object *> &objects, vector<HitboxObject *> &hitboxObjects, vector<Entity *> &entities, Camera *cam, Boundry *boundry, float g)
    : objects(objects), hitboxObjects(hitboxObjects), entities(entities), cam(cam), boundry(boundry) {
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
  Entity *e;
  bool collided;
  for (int i = 0; i < entities.size(); i++) {
    e = entities[i];
    for (int j = 0; j < hitboxObjects.size(); j++) {
      if (e == hitboxObjects[j])
        continue;

      if (e->collide(*hitboxObjects[j]))
        collided = true;

      e->checkInBoundries(*this->boundry);
    }
  }
  if (!collided) {
    e->setOnWallRight(false);
    e->setOnWallLeft(false);
    e->setOnGround(false);
  }
}

void GameController::loopTick() {
  float timespan = min(this->getTickTimespan(), 0.016f);
  if (this->entities.size() > 0) {

    this->update(timespan);
    this->checkCollisions();
    if (this->boundry == nullptr)
      this->cam->update();
    else
      this->cam->update(this->boundry);
  }
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

void GameController::setCamera(Camera *cam) {
  this->cam = cam;
}

void GameController::setBoundry(Boundry *boundry) {
  this->boundry = boundry;
}