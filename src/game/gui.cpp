#include "game/gui.h"
#include <algorithm>
using std::find;

GUI::GUI(vector<Component *> components) : components(components) {}

void GUI::add(Component *comp) {
  auto idx = find(this->components.begin(), this->components.end(), comp);
  if (idx == this->components.end())
    this->components.push_back(comp);
}

void GUI::remove(Component *comp) {
  auto idx = find(this->components.begin(), this->components.end(), comp);
  if (idx != this->components.end())
    this->components.erase(idx);
}

void GUI::draw(HDC canvas) {
  for (int i = 0; i < this->components.size(); i++)
    this->components[i]->draw(canvas);
}