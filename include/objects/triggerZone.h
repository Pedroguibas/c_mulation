#pragma once

#ifndef TRIGGER_ZONE_H
#define TRIGGER_ZONE_H

#include <vector>
#include <functional>
#include "objects/box.h"
using std::vector;
using std::function;

class Entity;

class TriggerZone : public Box {
private:
  function<void()> func;
  bool single; // defines if can activate multiple times
  vector<Entity *> observedEntities;
  vector<Entity *> entitiesIn;

  void runFunc(Entity *ent);
  void entityEnter(Entity *ent);
  void entityLeave(Entity *ent);

public:
  TriggerZone(int width, int height, int x, int y, bool single, vector<Entity *> observedEntities, function<void()> func);

  void checkTrigger();


  void observeEntity(Entity *ent);
  void stopObservingEntity(Entity *ent);
  
};

#endif