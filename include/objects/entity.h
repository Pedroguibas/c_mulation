#ifndef ENTITY_H
#define ENTITY_H

#include "objects/hitboxObject.h"
#include <cmath>
using std::max;
using std::min;

class Entity : public HitboxObject {
private:
  float speedX;
  float speedY;

public:
  Entity(int width, int height);
  Entity(int width, int height, int x, int y);
  Entity(int width, int height, int x, int y, const Color &color);
  Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness);
  virtual void update(float timespan);

  void setSpeedX(float speed);
  float getSpeedX();

  void setSpeedY(float speed);
  float getSpeedY();

  void pushout(HitboxObject &obj) override;
};

#endif