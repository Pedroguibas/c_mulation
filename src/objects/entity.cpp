#include "objects/entity.h"

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
void Entity::update() {
  this->setX(this->getX() + this->getSpeedX());
  this->setY(this->getY() + this->getSpeedY());
}

void Entity::setSpeedX(int speed) {
  this->speedX = speed;
}
int Entity::getSpeedX() {
  return this->speedX;
}

void Entity::setSpeedY(int speed) {
  this->speedY = speed;
}
int Entity::getSpeedY() {
  return this->speedY;
}