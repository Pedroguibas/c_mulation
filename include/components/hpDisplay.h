#pragma once

#ifndef HP_DISPLAY_H
#define HP_DISPLAY_H

#include "components/component.h"

class Mob;

class HpDisplay : public Component {
private:
  Mob *mob;
  Color &heartColor;

public:
  HpDisplay(int x, int y, Color &color, Color &heartColor, Mob *mob);

  void setMob(Mob *mob);

  void setHeartColor(Color &color);

  void draw(HDC canvas) override;
};

#endif