#pragma once

#ifndef GUI_H
#define GUI_H

#include "components/component.h"
#include <vector>
using std::vector;

class GUI {
private:
  vector<Component *> &components;

public:
  GUI(vector<Component *> &components);

  void add(Component *comp);
  void remove(Component *comp);

  void draw(HDC canvas);
};

#endif