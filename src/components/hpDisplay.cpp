#include "components/hpDisplay.h"
#include "components/text.h"
#include "objects/mob.h"

HpDisplay::HpDisplay(int x, int y, Color &color, Color &heartColor, Mob *mob) : ColorfulComponent(x, y, color), mob(mob), heartColor(heartColor) {}

void HpDisplay::setMob(Mob *mob) {
  this->mob = mob;
}

void HpDisplay::setHeartColor(Color &color) {
  this->heartColor = color;
}

void HpDisplay::draw(HDC canvas) {
  Text title("HP:", 24, this->getX(), this->getY(), this->getColor());

  string hearts = "";

  for (int i = 0; i < this->mob->getHp(); i++)
    hearts += "❤️";

  Text hp(hearts, 24, this->getX() + title.getWidth(), this->getY(), this->heartColor);

  title.draw(canvas);
  hp.draw(canvas);
}