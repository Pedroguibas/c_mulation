#include "components/column.h"
#include "objects/color.h"
#include <iostream>

Column::Column(int x, int y, Color color, vector<Component *> children)
    : Component(x, y, color), children(children), gap(0) {
  this->updateHeight();
  this->updateWidth();
}

Column::Column(int x, int y, Color color, vector<Component *> children, int gap)
    : Component(x, y, color), children(children), gap(gap) {
  this->updateHeight();
  this->updateWidth();
}

Column::~Column() {
  for (Component *comp : this->children)
    delete comp;
}

void Column::setGap(int gap) {
  this->gap = gap;
}
int Column::getGap() {
  return this->gap;
}

void Column::updateHeight() {
  int totalHeight = this->getY();

  for (Component *comp : this->children) {
    comp->setY(totalHeight);
    totalHeight += comp->getHeight() + this->gap;
  }

  this->setHeight(totalHeight);
}

void Column::updateWidth() {
  int widest = 0;
  for (Component *comp : this->children) {
    if (widest < comp->getWidth())
      widest = comp->getWidth();
  }

  for (Component *comp : this->children) {
    comp->setX(this->getX() + widest / 2 - comp->getWidth() / 2);
  }

  this->setWidth(widest);
}

void Column::draw(HDC canvas) {
  this->updateHeight();
  this->updateWidth();
  for (Component *comp : this->children) {
    comp->draw(canvas);
  }
}