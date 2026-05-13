#pragma once

#ifndef TRIGGER_ZONE_H
#define TRIGGER_ZONE_H

#include "objects/box.h"
#include "objects/entity.h"
#include "objects/triggerZoneBase.h"
#include <functional>
#include <vector>
using std::function;
using std::vector;

template <typename T>
class TriggerZone : public Box, public TriggerZoneBase {
  static_assert(std::is_base_of<Entity, T>::value,
                "T must inherit from Entity");
  function<void(T *ent)> func;

private:
  bool single; // defines if can activate multiple times
  vector<T *> observedEntities;
  vector<T *> entitiesIn;

  void runFunc(T *ent);
  void entityEnter(T *ent);
  void entityLeave(T *ent);

public:
  TriggerZone(int width, int height, int x, int y, bool single, vector<T *> observedEntities, function<void(T *ent)> func);

  void checkTrigger() override;

  void observeEntity(T *ent);
  void stopObservingEntity(T *ent);
};

#include "triggerZone.tpp"

#endif