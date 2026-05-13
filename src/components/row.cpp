#include "components/row.h"

Row::Row(vector<Component *> children) : Flex(children) {
  this->updateHeight();
  this->updateWidth();
}
Row::Row(vector<Component *> children, int gap) : Flex(children, gap) {
  this->updateHeight();
  this->updateWidth();
}
Row::Row(int x, int y, vector<Component *> children) : Flex(x, y, children) {
  this->updateHeight();
  this->updateWidth();
}
Row::Row(int x, int y, vector<Component *> children, int gap) : Flex(x, y, children, gap) {
  this->updateHeight();
  this->updateWidth();
}

void Row::updateHeight() {
  int tallest = 0;
  for (auto *comp : *this->getChildren()) {
    if (tallest < comp->getHeight())
      tallest = comp->getHeight();
  }

  for (auto *comp : *this->getChildren()) comp->setY(this->getY() + tallest / 2 - comp->getHeight() / 2);

  this->setHeight(tallest);
}
void Row::updateWidth() {
  int totalWidth = 0;
  for (auto *comp : *this->getChildren()) {
    comp->setX(this->getX() + totalWidth);

    totalWidth += comp->getWidth() + this->getGap();
  }
  totalWidth -= this->getGap();

  this->setWidth(totalWidth);
}

void Row::draw(HDC canvas) {
  for (auto *comp : *this->getChildren()) comp->draw(canvas);
}