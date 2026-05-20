#include "objects/scriptedMob.h"

ScriptedMob::ScriptedMob(int width, int height, int hp, int x, int y) : Mob(width, height, hp, x, y) {}
ScriptedMob::ScriptedMob(int width, int height, int hp, int x, int y, const Color &color)
    : Mob(width, height, hp, x, y, color) {}
ScriptedMob::ScriptedMob(
    int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness)
    : Mob(width, height, hp, x, y, color, border, borderThickness) {}
ScriptedMob::ScriptedMob(int width,
                         int height,
                         int hp,
                         int x,
                         int y,
                         const Color &color,
                         const Color &border,
                         int borderThickness,
                         float maxSpeed)
    : Mob(width, height, hp, x, y, color, border, borderThickness, maxSpeed) {}
ScriptedMob::ScriptedMob(int width,
                         int height,
                         int hp,
                         int x,
                         int y,
                         const Color &color,
                         const Color &border,
                         int borderThickness,
                         float maxSpeedX,
                         float maxSpeedY)
    : Mob(width, height, hp, x, y, color, border, borderThickness, maxSpeedX, maxSpeedY) {}

void ScriptedMob::update(float timespan) {
  Mob::update(timespan);
  this->onUpdate(timespan);
}

void ScriptedMob::setOnUpdate(function<void(float timespan)> onUpdate) {
  this->onUpdate = onUpdate;
}
function<void(float timespan)> ScriptedMob::getOnUpdate() {
  return this->onUpdate;
}