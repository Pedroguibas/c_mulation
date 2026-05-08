#include "objects/object.h"
#include "game/camera.h"

Object::Object(int width, int height, int x, int y) : Box(width, height, x, y), color(255, 255, 255), border(255, 255, 255) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(x);
  this->setY(y);
  this->setBorderThickness(0);
}

Object::Object(int width, int height, int x, int y, const Color &color) : Box(width, height, x, y), color(color), border(color) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(x);
  this->setY(y);
  this->setBorderThickness(0);
}

Object::Object(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness) : Box(width, height, x, y), color(color), border(border) {
  this->setWidth(width);
  this->setHeight(height);
  this->setX(x);
  this->setY(y);
  this->setBorderThickness(borderThickness);
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

void Object::draw(HDC canvas, Camera &cam) {
  HBRUSH brush = CreateSolidBrush(RGB(this->getColor().getR(), this->getColor().getG(), this->getColor().getB()));
  HPEN pen = CreatePen(PS_SOLID, this->getBorderThickness(), RGB(this->getBorder().getR(), this->getBorder().getG(), this->getBorder().getB()));

  HBRUSH oldBrush = (HBRUSH)SelectObject(canvas, brush);
  HPEN oldPen = (HPEN)SelectObject(canvas, pen);

  int borderDif = this->borderThickness / 2;

  Rectangle(
      canvas,
      this->getLeft() + borderDif - cam.getX(),
      this->getTop() + borderDif - cam.getY(),
      this->getRight() - borderDif - cam.getX(),
      this->getBottom() - borderDif - cam.getY());

  SelectObject(canvas, oldBrush);
  SelectObject(canvas, oldPen);

  DeleteObject(brush);
  DeleteObject(pen);
}