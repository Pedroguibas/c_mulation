#pragma once

#ifndef MOB_H
#define MOB_H

#include "objects/entity.h"
#include <functional>
using std::function;

class Mob : public Entity {

private:
  int hp;
  bool alive;
  bool invincible;
  function<void()> onDeath;

public:
  Mob(int width, int height, int hp);
  Mob(int width, int height, int hp, int x, int y);
  Mob(int width, int height, int hp, int x, int y, const Color &color);
  Mob(int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness);
  Mob(int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeed);
  Mob(int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeedX, float maxSpeedY);

  void update(float timespan) override;

  void setInvincible(bool invincible);
  bool isInvincible();

  void setHp(int hp);
  int getHp();

  void setAlive(bool ailve);
  bool isAlive();

  void setOnDeath(function<void()> func);

  void takeDamage(int dmg);

  void die();
};

#endif