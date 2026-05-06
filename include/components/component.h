#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include <windows.h>

class Color;

class Component {
private:
  int x;
  int y;
  Color &color;

public:
  Component(int x, int y, Color &color);

  void setX(int x);
  int getX();
  void setY(int y);
  int getY();

  void setColor(Color &color);
  Color &getColor();

  virtual void draw(HDC canvas);
};

#endif