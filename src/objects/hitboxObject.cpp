#include "objects/hitboxObject.h"
#include <cmath>
using std::max;
using std::min;

HitboxObject::HitboxObject(int width, int height) : Object(width, height) {
}

HitboxObject::HitboxObject(int width, int height, int x, int y) : Object(width, height, x, y) {
}

HitboxObject::HitboxObject(int width, int height, int x, int y, const Color &color) : Object(width, height, x, y, color) {
}

HitboxObject::HitboxObject(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness) : Object(width, height, x, y, color, border, borderThickness) {
}

bool HitboxObject::collide(HitboxObject obj) {
  if (
      (this->getTop() < obj.getBottom() && this->getBottom() > obj.getTop()) &&
      (this->getLeft() < obj.getRight() && this->getRight() > obj.getLeft())) {
    this->pushout(obj);
    return true;
  }

  return false;
}

void HitboxObject::pushout(HitboxObject obj) {
  int xOverlap = min(this->getRight(), obj.getRight()) - max(this->getLeft(), obj.getLeft());
  int yOverlap = min(this->getBottom(), obj.getBottom()) - max(this->getTop(), obj.getTop());
  if (xOverlap < yOverlap) {
    if (this->getX() > obj.getX())
      this->setX(obj.getRight() + this->getWidth() / 2);
    else
      this->setX(obj.getLeft() - this->getWidth() / 2);
  } else {
    if (this->getY() > obj.getY())
      this->setY(obj.getBottom() + this->getHeight() / 2);
    else
      this->setY(obj.getTop() - this->getHeight() / 2);
  }
}
