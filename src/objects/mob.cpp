#include "objects/mob.h"
#include <iostream>

Mob::Mob(int width, int height, int hp) : Entity(width, height), hp(hp) {}
Mob::Mob(int width, int height, int hp, int x, int y) : Entity(width, height, x, y), hp(hp) {}
Mob::Mob(int width, int height, int hp, int x, int y, const Color &color) : Entity(width, height, x, y, color), hp(hp) {}
Mob::Mob(int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness) : Entity(width, height, x, y, color, border, borderThickness), hp(hp) {}
Mob::Mob(int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeed) : Entity(width, height, x, y, color, border, borderThickness, maxSpeed), hp(hp) {}
Mob::Mob(int width, int height, int hp, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeedX, float maxSpeedY) : Entity(width, height, x, y, color, border, borderThickness, maxSpeedX, maxSpeedY), hp(hp) {}

void Mob::update(float timespan) {
  Entity::update(timespan);
}

void Mob::setInvincible(bool invincible) {
  this->invincible = invincible;
}
bool Mob::isInvincible() {
  return this->invincible;
}

void Mob::setHp(int hp) {
  this->hp = hp;
}
int Mob::getHp() {
  return this->hp;
}

void Mob::setAlive(bool alive) {
  this->alive = alive;
}
bool Mob::isAlive() {
  return this->alive;
}

void Mob::takeDamage(int dmg) {
  this->hp -= dmg;

  if (this->getHp() <= 0)
    this->die();
}

void Mob::die() {
  this->setAlive(false);
  this->onDeath();
}

void Mob::setOnDeath(function<void()> func) {
  this->onDeath = func;
}