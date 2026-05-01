#include "objects/entity.h"
#include <cmath>

Entity::Entity(int width, int height) : HitboxObject(width, height) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y) : HitboxObject(width, height, x, y) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y, const Color &color) : HitboxObject(width, height, x, y, color) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness) : HitboxObject(width, height, x, y, color, border, borderThickness) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
void Entity::update(float timespan) {
  this->setX(this->getX() + round(this->getSpeedX() * timespan));
  this->setY(this->getY() + round(this->getSpeedY() * timespan));
}

void Entity::setSpeedX(float speed) {
  this->speedX = speed;
}
float Entity::getSpeedX() {
  return this->speedX;
}

void Entity::setSpeedY(float speed) {
  this->speedY = speed;
}
float Entity::getSpeedY() {
  return this->speedY;
}

void Entity::pushout(HitboxObject &obj) {
  int xOverlap = min(this->getRight(), obj.getRight()) - max(this->getLeft(), obj.getLeft());
  int yOverlap = min(this->getBottom(), obj.getBottom()) - max(this->getTop(), obj.getTop());
  if (xOverlap < yOverlap) {
    if (this->getX() > obj.getX())
      this->setX(obj.getRight() + this->getWidth() / 2);
    else
      this->setX(obj.getLeft() - this->getWidth() / 2);

    this->setSpeedX(0);
  } else {
    if (this->getY() > obj.getY())
      this->setY(obj.getBottom() + this->getHeight() / 2);
    else
      this->setY(obj.getTop() - this->getHeight() / 2);

    this->setSpeedY(0);
  }
}