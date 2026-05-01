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

class GameController {
private:
  vector<Object *> &objects;
  vector<HitboxObject *> &hitboxObjects;
  vector<Entity *> &entities;
  float gravity = 1500;
  steady_clock::time_point lastTick;

public:
  GameController(vector<Object *> &objects, vector<HitboxObject *> &hitboxObjects, vector<Entity *> &entities);
  GameController(vector<Object *> &objects, vector<HitboxObject *> &hitboxObjects, vector<Entity *> &entities, float g);

  void update(float timespan);

  void checkCollisions();

  void loopTick();

  void setLastTick();
  float getLastTick();

  float getTickTimespan();
};

#endif