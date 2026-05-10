#include "components/center.h"
#include "objects/color.h"
#include <iostream>

Center::Center(int width, int height, int x, int y, Color color, Component *child)
    : Component(x, y, color), child(child) {
  this->setWidth(width);
  this->setHeight(height);
}

Center::Center(int width, int x, int y, Color color, Component *child)
    : Component(x, y, color), child(child) {
  this->setWidth(width);
  this->setHeight(-1);
}

void Center::draw(HDC canvas) {
  int newX = this->getX() + this->getWidth() / 2 - this->child->getWidth() / 2;
  int newY = this->getY();

  if (this->getHeight() > 0) {
    newY += this->getHeight() / 2 - this->child->getHeight() / 2;
  }

  this->child->setX(newX);
  this->child->setY(newY);

  this->child->draw(canvas);
}