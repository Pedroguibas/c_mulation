#include "game/camera.h"
#include "objects/boundry.h"

Camera::Camera(int topLimit, int rightLimit, int bottomLimit, int leftLimit, Entity *ent) : focusEnt(ent) {
  this->setTopLimit(topLimit);
  this->setRightLimit(rightLimit);
  this->setBottomLimit(bottomLimit);
  this->setLeftLimit(leftLimit);
}
Camera::Camera(int *limits, Entity *ent) : focusEnt(ent) {
  this->setTopLimit(limits[0]);
  this->setRightLimit(limits[1]);
  this->setBottomLimit(limits[2]);
  this->setLeftLimit(limits[3]);
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
  else if (this->focusEnt->getLeft() - newX < this->getLeftLimit())
    newX = this->focusEnt->getLeft() - this->getLeftLimit();

  if (this->focusEnt->getRight() - newX > this->getRightLimit())
    newX = this->focusEnt->getRight() - this->getRightLimit();
  else if (this->focusEnt->getBottom() - newY > this->getBottomLimit())
    newY = this->focusEnt->getBottom() - this->getBottomLimit();

  this->setX(newX);
  this->setY(newY);
}

void Camera::update(Boundry *boundry) {
  float newX = this->getX();
  float newY = this->getY();

  if (this->focusEnt->getTop() - newY < this->getTopLimit())
    newY = this->focusEnt->getTop() - this->getTopLimit();
  else if (this->focusEnt->getBottom() - newY > this->getBottomLimit())
    newY = this->focusEnt->getBottom() - this->getBottomLimit();

  if (this->focusEnt->getRight() - newX > this->getRightLimit())
    newX = this->focusEnt->getRight() - this->getRightLimit();
  else if (this->focusEnt->getLeft() - newX < this->getLeftLimit())
    newX = this->focusEnt->getLeft() - this->getLeftLimit();

  if (newX < boundry->getLeft())
    newX = boundry->getLeft();
  else if (newX + boundry->getWindowWidth() > boundry->getRight())
    newX = boundry->getRight() - boundry->getWindowWidth();

  if (newY < boundry->getTop())
    newY = boundry->getTop();
  else if (newY + boundry->getWindowHeight() > boundry->getBottom())
    newY = boundry->getBottom() - boundry->getWindowHeight();

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