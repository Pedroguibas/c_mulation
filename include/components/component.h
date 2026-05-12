#pragma once

#ifndef COMPONENT_H
#define COMPONENT_H

#include <windows.h>

class Component {
private:
  int x;
  int y;
  int width;
  int height;

public:
  Component(int x, int y);
  virtual ~Component() {}

  virtual void setX(int x);
  int getX();
  virtual void setY(int y);
  int getY();

  void setWidth(int w);
  int getWidth();
  void setHeight(int h);
  int getHeight();

  virtual void updateHeight();
  virtual void updateWidth();
  virtual void draw(HDC canvas);
};

#endif