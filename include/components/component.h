#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include <windows.h>

class Color;

class Component {
private:
  int x;
  int y;
  int width;
  int height;
  Color &color;

public:
  Component(int x, int y, Color &color);
  virtual ~Component() {}

  void setX(int x);
  int getX();
  void setY(int y);
  int getY();

  void setWidth(int w);
  int getWidth();
  void setHeight(int h);
  int getHeight();

  void setColor(Color &color);
  Color &getColor();

  virtual void updateHeight();
  virtual void updateWidth();
  virtual void draw(HDC canvas);
};

#endif