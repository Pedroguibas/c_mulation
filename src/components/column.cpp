#include "components/column.h"

#include <iostream>

#include "objects/color.h"

Column::Column(vector<Component *> children) : Flex(children) {
  this->updateHeight();
  this->updateWidth();
}
Column::Column(vector<Component *> children, int gap) : Flex(children, gap) {
  this->updateHeight();
  this->updateWidth();
}
Column::Column(int x, int y, vector<Component *> children) : Flex(x, y, children) {
  this->updateHeight();
  this->updateWidth();
}
Column::Column(int x, int y, vector<Component *> children, int gap) : Flex(x, y, children, gap) {
  this->updateHeight();
  this->updateWidth();
}

void Column::updateHeight() {
  int totalHeight = 0;

  for (Component *comp : *this->getChildren()) {
    comp->setY(this->getY() + totalHeight);
    totalHeight += comp->getHeight() + this->getGap();
  }
  totalHeight -= this->getGap();

  this->setHeight(totalHeight);
}

void Column::updateWidth() {
  int widest = 0;
  for (Component *comp : *this->getChildren()) {
    if (widest < comp->getWidth())
      widest = comp->getWidth();
  }

  for (Component *comp : *this->getChildren()) comp->setX(this->getX() + widest / 2 - comp->getWidth() / 2);

  this->setWidth(widest);
}

void Column::draw(HDC canvas) {
  this->updateHeight();
  this->updateWidth();
  for (Component *comp : *this->getChildren()) {
    comp->draw(canvas);
  }
}