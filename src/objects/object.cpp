#include "objects/object.h"

Object::Object(int width, int height) : color(255, 255, 255), border(255, 255, 255) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(0);
  this->setY(0);
  this->setBorderThickness(0);
}

Object::Object(int width, int height, int x, int y) : color(255, 255, 255), border(255, 255, 255) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(x);
  this->setY(y);
  this->setBorderThickness(0);
}

Object::Object(int width, int height, int x, int y, const Color &color) : color(color), border(color) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(x);
  this->setY(y);
  this->setBorderThickness(0);
}

Object::Object(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness) : color(color), border(border) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(x);
  this->setY(y);
  this->setBorderThickness(borderThickness);
}

void Object::setWidth(int w) {
  this->width = w;
}
int Object::getWidth() {
  return this->width;
}

void Object::setHeight(int h) {
  this->height = h;
}
int Object::getHeight() {
  return this->height;
}

void Object::setX(int x) {
  this->x = x;
  this->left = x - this->width / 2;
  this->right = x + this->width / 2;
}
int Object::getX() {
  return this->x;
}

void Object::setY(int y) {
  this->y = y;
  this->top = y - this->height / 2;
  this->bottom = y + this->height / 2;
}
int Object::getY() {
  return this->y;
}

int Object::getTop() {
  return this->top;
}
int Object::getRight() {
  return this->right;
}
int Object::getBottom() {
  return this->bottom;
}
int Object::getLeft() {
  return this->left;
}

void Object::setColor(Color color) {
  this->color = color;
}
Color Object::getColor() {
  return this->color;
}

void Object::setBorder(Color border) {
  this->border = border;
}
Color Object::getBorder() {
  return this->border;
}

void Object::setBorderThickness(int t) {
  if (t >= 0)
    this->borderThickness = t;
}

int Object::getBorderThickness() {
  return this->borderThickness;
}