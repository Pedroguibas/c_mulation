#pragma once

#ifndef VISIBLE_TRIGGER_ZONE_H
#define VISIBLE_TRIGGER_ZONE_H

#include "objects/Object.h"
#include "objects/entity.h"
#include "objects/triggerZone.h"

template <typename T>
class VisibleTriggerZone : public Object, public TriggerZone<T> {
  static_assert(std::is_base_of<Entity, T>::value,
                "T must inherit from Entity");
  function<void(T *ent)> func;

public:
  VisibleTriggerZone(int width, int height, int x, int y, bool single, vector<T *> observedEntities, function<void(T *ent)> func);
  VisibleTriggerZone(int width, int height, int x, int y, Color color, bool single, vector<T *> observedEntities, function<void(T *ent)> func);
  VisibleTriggerZone(int width, int height, int x, int y, Color color, Color border, int borderThickness, bool single, vector<T *> observedEntities, function<void(T *ent)> func);
};

#endif

#include "visibleTriggerZone.tpp"