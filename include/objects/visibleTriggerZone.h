#pragma once

#ifndef VISIBLE_TRIGGER_ZONE_H
#define VISIBLE_TRIGGER_ZONE_H

#include "objects/Object.h"
#include "objects/triggerZone.h"

class Entity;

class VisibleTriggerZone : public Object, public TriggerZone {
public:
  VisibleTriggerZone(int width, int height, int x, int y, bool single, vector<Entity *> observedEntities, function<void()> func);
  VisibleTriggerZone(int width, int height, int x, int y, Color color, bool single, vector<Entity *> observedEntities, function<void()> func);
  VisibleTriggerZone(int width, int height, int x, int y, Color color, Color border, int borderThickness, bool single, vector<Entity *> observedEntities, function<void()> func);
};

#endif