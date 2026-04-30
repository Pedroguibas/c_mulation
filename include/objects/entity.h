#ifndef ENTITY_H
#define ENTITY_H

#include "objects/hitboxObject.h"

class Entity : public HitboxObject {
  private:
    int speedX;
    int speedY;

  public:
    Entity(int width, int height);
    Entity(int width, int height, int x, int y);
    Entity(int width, int height, int x, int y, const Color &color);
    Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness);
    virtual void update();

    void setSpeedX(int speed);
    int getSpeedX();

    void setSpeedY(int speed);
    int getSpeedY();

};

#endif