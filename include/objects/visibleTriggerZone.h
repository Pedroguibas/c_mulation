#pragma once

#ifndef VISIBLE_TRIGGER_ZONE_H
#define VISIBLE_TRIGGER_ZONE_H

#include "objects/Object.h"
#include "objects/box.h"
#include <functional>
#include <vector>
using std::function;
using std::vector;

class Entity;

class VisibleTriggerZone : public Object {
private:
  function<void()> func;
  bool single; // defines if can activate multiple times
  vector<Entity *> observedEntities;
  vector<Entity *> entitiesIn;

  void runFunc(Entity *ent);
  void entityEnter(Entity *ent);
  void entityLeave(Entity *ent);

public:
  VisibleTriggerZone(int width, int height, int x, int y, bool single, vector<Entity *> observedEntities, function<void()> func);

  void checkTrigger();

  void observeEntity(Entity *ent);
  void stopObservingEntity(Entity *ent);
};

#endif