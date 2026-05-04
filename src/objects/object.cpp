#include "objects/object.h"
#include "game/camera.h"

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

void Object::draw(HDC canvas) {
  HBRUSH brush = CreateSolidBrush(RGB(this->getColor().getR(), this->getColor().getG(), this->getColor().getB()));
  HPEN pen = CreatePen(PS_SOLID, this->getBorderThickness(), RGB(this->getBorder().getR(), this->getBorder().getG(), this->getBorder().getB()));

  HBRUSH oldBrush = (HBRUSH)SelectObject(canvas, brush);
  HPEN oldPen = (HPEN)SelectObject(canvas, pen);

  int borderDif = this->borderThickness / 2;

  Rectangle(
      canvas,
      this->getLeft() + borderDif,
      this->getTop() + borderDif,
      this->getRight() - borderDif,
      this->getBottom() - borderDif);

  SelectObject(canvas, oldBrush);
  SelectObject(canvas, oldPen);

  DeleteObject(brush);
  DeleteObject(pen);
}

void Object::draw(HDC canvas, Camera *cam) {
  HBRUSH brush = CreateSolidBrush(RGB(this->getColor().getR(), this->getColor().getG(), this->getColor().getB()));
  HPEN pen = CreatePen(PS_SOLID, this->getBorderThickness(), RGB(this->getBorder().getR(), this->getBorder().getG(), this->getBorder().getB()));

  HBRUSH oldBrush = (HBRUSH)SelectObject(canvas, brush);
  HPEN oldPen = (HPEN)SelectObject(canvas, pen);

  int borderDif = this->borderThickness / 2;

  Rectangle(
      canvas,
      this->getLeft() + borderDif - cam->getX(),
      this->getTop() + borderDif - cam->getY(),
      this->getRight() - borderDif - cam->getX(),
      this->getBottom() - borderDif - cam->getY());

  SelectObject(canvas, oldBrush);
  SelectObject(canvas, oldPen);

  DeleteObject(brush);
  DeleteObject(pen);
}