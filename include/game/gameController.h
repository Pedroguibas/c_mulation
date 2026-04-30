#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "objects/object.h"
#include "objects/HitboxObject.h"
#include "objects/entity.h"
#include <vector>
using std::vector;

class GameController {
private:
  vector<Object*>& objects;
  vector<HitboxObject*>& hitboxObjects;
  vector<Entity*>& entities;

public:
  GameController(vector<Object*> &objects, vector<HitboxObject*> &hitboxObjects, vector<Entity*> &entities);

  void update();

  void testCollisions();
};

#endif