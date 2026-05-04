#pragma once

#ifndef HITBOX_OBJECT_H
#define HITBOX_OBJECT_H

#include "object.h"

class HitboxObject : public Object {
public:
  HitboxObject(int width, int height);
  HitboxObject(int width, int height, int x, int y);
  HitboxObject(int width, int height, int x, int y, const Color &color);
  HitboxObject(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness);

  bool collide(HitboxObject &obj);

  virtual void pushout(HitboxObject &obj);
};

#endif