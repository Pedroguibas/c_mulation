#pragma once

#ifndef TRIGGER_ZONE_H
#define TRIGGER_ZONE_H

#include <vector>
#include <functional>
#include "objects/box.h"
using std::vector;
using std::function;

class Entity;

template <typename T>
class TriggerZone : public Box {
private:
  function<void()> func;
  bool single; // defines if can activate multiple times
  vector<T *> observedEntities;
  vector<T *> entitiesIn;

  void runFunc(T *ent);
  void entityEnter(T *ent);
  void entityLeave(T *ent);

public:
  TriggerZone(int width, int height, int x, int y, bool single, vector<T *> observedEntities, function<void(T *ent)> func);

  void checkTrigger();


  void observeEntity(T *ent);
  void stopObservingEntity(T *ent);
  
};

#endif