#include "objects/color.h"

Color::Color(int r, int g, int b) {
  this->setR(r);
  this->setG(g);
  this->setB(b);
}

void Color::setR(int r) {
  if (r > 255)
    this->r = 255;
  else if (r < 0)
    this->r = 0;
  else
    this->r = r;
}
int Color::getR() {
  return this->r;
}

void Color::setG(int g) {
  if (g > 255)
    this->g = 255;
  else if (g < 0)
    this->g = 0;
  else
    this->g = g;
}
int Color::getG() {
  return this->g;
}

void Color::setB(int b) {
  if (b > 255)
    this->b = 255;
  else if (b < 0)
    this->b = 0;
  else
    this->b = b;
}
int Color::getB() {
  return this->b;
}