#pragma once

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "objects/HitboxObject.h"
#include "objects/entity.h"
#include "objects/mob.h"
#include "objects/object.h"
#include "objects/triggerZoneBase.h"
#include <chrono>
#include <cmath>
#include <vector>
using std::min;
using std::vector;
using std::chrono::duration;
using std::chrono::seconds;
using std::chrono::steady_clock;

class Camera;
class Boundry;

class GameController {
private:
  vector<HitboxObject *> hitboxObjects;
  vector<Entity *> entities;
  vector<TriggerZoneBase *> triggerZones;
  Mob *player;
  float gravity = 1500;
  steady_clock::time_point lastTick;
  Camera *cam;
  Boundry *boundry;

public:
  GameController(Mob *player, vector<HitboxObject *> hitboxObjects, vector<Entity *> entities, vector<TriggerZoneBase *> triggerZones, Camera *cam, Boundry *boundry);
  GameController(Mob *player, vector<HitboxObject *> hitboxObjects, vector<Entity *> entities, vector<TriggerZoneBase *> triggerZones, Camera *cam, Boundry *boundry, float g);

  void update(float timespan);

  void checkCollisions();
  void checkPlayerCollisions();
  void checkTriggers();

  void loopTick();

  void setLastTick();
  float getLastTick();

  float getTickTimespan();

  void setCamera(Camera *cam);

  void setBoundry(Boundry *boundry);

  void setPlayer(Mob *player);

  void appendTriggerZone(TriggerZoneBase *triggerZone);
  void removeTriggerZone(TriggerZoneBase *triggerZone);
  void appendHitbox(HitboxObject *hitbox);
  void removeHitbox(HitboxObject *hitbox);
  void appendEntity(Entity *ent);
  void removeEntity(Entity *ent);
};

#endif