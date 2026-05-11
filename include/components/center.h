#pragma once

#ifndef CENTER_H
#define CENTER_H

#include "components/component.h"

class Color;

class Center : public Component {
private:
  Component *child;

public:
  Center(int widht, int height, int x, int y, Color color, Component *child);
  Center(int widht, int x, int y, Color color, Component *child);

  void draw(HDC canvas) override;
};

#endif