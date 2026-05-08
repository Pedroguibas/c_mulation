#include "objects/box.h"

Box::Box(int width, int height, int x, int y) : width(width), height(height) {
  this->setX(x);
  this->setY(y);
}

void Box::setWidth(int w) {
  this->width = w;
}
int Box::getWidth() {
  return this->width;
}

void Box::setHeight(int h) {
  this->height = h;
}
int Box::getHeight() {
  return this->height;
}

void Box::setX(int x) {
  this->x = x;
  this->left = x - this->width / 2;
  this->right = x + this->width / 2;
}
int Box::getX() {
  return this->x;
}

void Box::setY(int y) {
  this->y = y;
  this->top = y - this->height / 2;
  this->bottom = y + this->height / 2;
}
int Box::getY() {
  return this->y;
}

int Box::getTop() {
  return this->top;
}
int Box::getRight() {
  return this->right;
}
int Box::getBottom() {
  return this->bottom;
}
int Box::getLeft() {
  return this->left;
}