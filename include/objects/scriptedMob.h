#pragma once

#ifndef SCRIPTEDO_MOB_H
#define SCRIPTEDO_MOB_H

#include <functional>
using std::function;

#include "objects/mob.h"

class ScriptedMob : public Mob {
private:
  function<void(float timespan)> onUpdate;

public:
  ScriptedMob(int width, int height, int hp, int x, int y);
  ScriptedMob(int width, int height, int hp, int x, int y, const Color &color);
  ScriptedMob(
      int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness);
  ScriptedMob(int width,
              int height,
              int hp,
              int x,
              int y,
              const Color &color,
              const Color &border,
              int borderThickness,
              float maxSpeed);
  ScriptedMob(int width,
              int height,
              int hp,
              int x,
              int y,
              const Color &color,
              const Color &border,
              int borderThickness,
              float maxSpeedX,
              float maxSpeedY);

  void update(float timespan) override;

  void setOnUpdate(function<void(float timespan)> onUpdate);
  function<void(float timespan)> getOnUpdate();
};

#endif