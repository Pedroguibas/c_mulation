#include "game/camera.h"

Camera::Camera(int topLimit, int rightLimit, int bottomLimit, int leftLimit, Entity *ent) : focusEnt(ent) {
  this->setTopLimit(topLimit);
  this->setRightLimit(rightLimit);
  this->setBottomLimit(bottomLimit);
  this->setLeftLimit(leftLimit);
}

void Camera::setX(int x) {
  this->x = x;
}
int Camera::getX() {
  return this->x;
}
void Camera::setY(int y) {
  this->y = y;
}
int Camera::getY() {
  return this->y;
}

void Camera::update() {
  float newX = this->getX();
  float newY = this->getY();

  if (this->focusEnt->getTop() - newY < this->getTopLimit())
    newY = this->focusEnt->getTop() - this->getTopLimit();
  if (this->focusEnt->getRight() - newX > this->getRightLimit())
    newX = this->focusEnt->getRight() - this->getRightLimit();
  if (this->focusEnt->getBottom() - newY > this->getBottomLimit())
    newY = this->focusEnt->getBottom() - this->getBottomLimit();
  if (this->focusEnt->getLeft() - newX < this->getLeftLimit())
    newX = this->focusEnt->getLeft() - this->getLeftLimit();

  this->setX(newX);
  this->setY(newY);
}

void Camera::setTopLimit(int limit) {
  this->topLimit = limit;
}
int Camera::getTopLimit() {
  return this->topLimit;
}
void Camera::setRightLimit(int limit) {
  this->rightLimit = limit;
}
int Camera::getRightLimit() {
  return this->rightLimit;
}
void Camera::setBottomLimit(int limit) {
  this->bottomLimit = limit;
}
int Camera::getBottomLimit() {
  return this->bottomLimit;
}
void Camera::setLeftLimit(int limit) {
  this->leftLimit = limit;
}
int Camera::getLeftLimit() {
  return this->leftLimit;
}