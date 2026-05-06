#include "game/gui.h"

GUI::GUI(vector<Component *> &components) : components(components) {}

void GUI::draw(HDC canvas) {
  for (int i = 0; i < this->components.size(); i++)
    this->components[i]->draw(canvas);
}