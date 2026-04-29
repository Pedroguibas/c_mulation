#include "objects/hitboxObject.h"

HitboxObject::HitboxObject(int width, int height) : Object(width, height) {
}

HitboxObject::HitboxObject(int width, int height, int x, int y) : Object(width, height, x, y) {
}

HitboxObject::HitboxObject(int width, int height, int x, int y, const Color &color) : Object(width, height, x, y, color) {
}

HitboxObject::HitboxObject(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness) : Object(width, height, x, y, color, border, borderThickness) {
}

bool HitboxObject::colide(HitboxObject obj) {
  return false;
}

void HitboxObject::pushout(HitboxObject obj) {
}
