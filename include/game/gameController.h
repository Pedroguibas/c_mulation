#pragma once

#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "objects/HitboxObject.h"
#include "objects/entity.h"
#include "objects/object.h"
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
  float gravity = 1500;
  steady_clock::time_point lastTick;
  Camera *cam;
  Boundry *boundry;

public:
  GameController(vector<HitboxObject *> hitboxObjects, vector<Entity *> entities, Camera *cam, Boundry *boundry);
  GameController(vector<HitboxObject *> hitboxObjects, vector<Entity *> entities, Camera *cam, Boundry *boundry, float g);

  void update(float timespan);

  void checkCollisions();

  void loopTick();

  void setLastTick();
  float getLastTick();

  float getTickTimespan();

  void setCamera(Camera *cam);

  void setBoundry(Boundry *boundry);

  void appendObject(Object *obj);
  void removeObject(Object *obj);
  void appendHitbox(HitboxObject *hitbox);
  void removeHitbox(HitboxObject *hitbox);
  void appendEntity(Entity *ent);
  void removeEntity(Entity *ent);
};

#endif