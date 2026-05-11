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
  ~Center();

  void updateWidth() override;
  void updateHeight() override;

  void draw(HDC canvas) override;
};

#endif