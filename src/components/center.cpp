#include "components/center.h"
#include "objects/color.h"
#include <iostream>

Center::Center(int width, int height, int x, int y, Component *child)
    : Component(x, y), child(child) {
  this->setWidth(width);
  this->setHeight(height);

  this->updateWidth();
  this->updateHeight();
}

Center::Center(int width, int x, int y, Component *child)
    : Component(x, y), child(child) {
  this->setWidth(width);
  this->setHeight(-1);

  this->updateWidth();
  this->updateHeight();
}

Center::~Center() {
  delete this->child;
}

void Center::updateWidth() {
  this->child->updateWidth();
  int newX = this->getX() + this->getWidth() / 2 - this->child->getWidth() / 2;

  this->child->setX(newX);
}

void Center::updateHeight() {
  this->child->updateHeight();
  int newY = this->getY();

  if (this->getHeight() > 0)
    newY += this->getHeight() / 2 - this->child->getHeight() / 2;

  this->child->setY(newY);
}

void Center::draw(HDC canvas) {
  this->child->draw(canvas);
}