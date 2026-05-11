#include "components/component.h"
#include "objects/color.h"

Component::Component(int x, int y, Color &color) : x(x), y(y), color(color) {}

void Component::setX(int x) {
  this->x = x;
}
int Component::getX() {
  return this->x;
}
void Component::setY(int y) {
  this->y = y;
}
int Component::getY() {
  return this->y;
}

void Component::setColor(Color &color) {
  this->color = color;
}
Color &Component::getColor() {
  return this->color;
}

void Component::setWidth(int w) {
  this->width = w;
}
int Component::getWidth() {
  return this->width;
}

void Component::setHeight(int h) {
  this->height = h;
}
int Component::getHeight() {
  return this->height;
}

void Component::draw(HDC canvas) {}

void Component::updateHeight() {}

void Component::updateWidth() {}