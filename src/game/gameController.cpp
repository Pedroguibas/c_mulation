#include "game/gameController.h"
#include "game/camera.h"
#include "objects/boundry.h"
#include "objects/mob.h"
#include <algorithm>
#include <iostream>
using std::find;

GameController::GameController(Mob *player, vector<HitboxObject *> hitboxObjects, vector<Entity *> entities, vector<TriggerZoneBase *> triggerZones, Camera *cam, Boundry *boundry)
    : player(player), hitboxObjects(hitboxObjects), entities(entities), triggerZones(triggerZones), cam(cam), boundry(boundry) {}

GameController::GameController(Mob *player, vector<HitboxObject *> hitboxObjects, vector<Entity *> entities, vector<TriggerZoneBase *> triggerZones, Camera *cam, Boundry *boundry, float g)
    : player(player), hitboxObjects(hitboxObjects), entities(entities), triggerZones(triggerZones), cam(cam), boundry(boundry) {
  this->gravity = g;
}

void GameController::update(float timespan) {
  for (auto *e : this->entities) {
    e->setSpeedY(e->getSpeedY() + this->gravity * timespan);
    e->update(timespan);
  }

  if (this->player == nullptr)
    return;

  this->player->setSpeedY(this->player->getSpeedY() + this->gravity * timespan);
  this->player->update(timespan);
}

void GameController::checkCollisions() {
  for (auto *e : entities) {
    for (auto *hb : this->hitboxObjects) {
      if (e == hb)
        continue;

      e->collide(*hb);

      e->checkInBoundries(*this->boundry);
    }
  }

  this->checkPlayerCollisions();
}

void GameController::checkPlayerCollisions() {
  if (this->player == nullptr)
    return;

  bool collided = false;
  for (auto *hb : hitboxObjects) {
    if (this->player->collide(*hb))
      collided = true;
  }
  this->player->checkInBoundries(*this->boundry);

  if (!collided) {
    this->player->setOnWallRight(false);
    this->player->setOnWallLeft(false);
    this->player->setOnGround(false);
  }
}

void GameController::checkTriggers() {
  for (auto *tz : this->triggerZones) {
    tz->checkTrigger();
  }
}

void GameController::loopTick() {
  float timespan = min(this->getTickTimespan(), 0.016f);

  this->update(timespan);
  this->checkCollisions();
  this->checkTriggers();
  if (this->boundry == nullptr)
    this->cam->update();
  else
    this->cam->update(this->boundry);
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

void GameController::appendHitbox(HitboxObject *hitbox) {
  auto idx = find(this->hitboxObjects.begin(), this->hitboxObjects.end(), hitbox);

  if (idx == this->hitboxObjects.end())
    this->hitboxObjects.push_back(hitbox);
}
void GameController::removeHitbox(HitboxObject *hitbox) {
  auto idx = find(this->hitboxObjects.begin(), this->hitboxObjects.end(), hitbox);

  if (idx != this->hitboxObjects.end())
    this->hitboxObjects.erase(idx);
}

void GameController::appendEntity(Entity *ent) {
  auto idx = find(this->entities.begin(), this->entities.end(), ent);

  if (idx == this->entities.end())
    this->entities.push_back(ent);

  appendHitbox(ent);
}
void GameController::removeEntity(Entity *ent) {
  auto idx = find(this->entities.begin(), this->entities.end(), ent);

  if (idx != this->entities.end())
    this->entities.erase(idx);

  removeHitbox(ent);
}

void GameController::setPlayer(Mob *player) {
  this->player = player;
}

void GameController::appendTriggerZone(TriggerZoneBase *triggerZone) {
  auto idx = find(this->triggerZones.begin(), this->triggerZones.end(), triggerZone);

  if (idx == this->triggerZones.end())
    this->triggerZones.push_back(triggerZone);
}
void GameController::removeTriggerZone(TriggerZoneBase *triggerZone) {
  auto idx = find(this->triggerZones.begin(), this->triggerZones.end(), triggerZone);

  if (idx != this->triggerZones.end())
    this->triggerZones.erase(idx);
}