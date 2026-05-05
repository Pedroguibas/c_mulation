#include "objects/boundry.h"

Boundry::Boundry(int *boundries, int w, int h) : windowHeight(h), windowWidth(w) {
  this->setTop(boundries[0]);
  this->setRight(boundries[1]);
  this->setBottom(boundries[2]);
  this->setLeft(boundries[3]);
}
Boundry::Boundry(int top, int right, int bottom, int left, int w, int h) : windowHeight(h), windowWidth(w) {
  this->setTop(top);
  this->setRight(right);
  this->setBottom(bottom);
  this->setLeft(left);
}

void Boundry::setWindowWidth(int w) {
  this->windowWidth = w;
}
int Boundry::getWindowWidth() {
  return this->windowWidth;
}
void Boundry::setWindowHeight(int h) {
  this->windowHeight = h;
}
int Boundry::getWindowHeight() {
  return this->windowHeight;
}

void Boundry::setTop(int top) {
  this->top = top;
}
int Boundry::getTop() {
  return this->top;
}
void Boundry::setRight(int right) {
  this->right = right;
}
int Boundry::getRight() {
  return this->right;
}
void Boundry::setBottom(int bottom) {
  this->bottom = bottom;
}
int Boundry::getBottom() {
  return this->bottom;
}
void Boundry::setLeft(int left) {
  this->left = left;
}
int Boundry::getLeft() {
  return this->left;
}