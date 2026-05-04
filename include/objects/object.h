#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include "color.h"
#include <windows.h>

class Object {
private:
  int width;
  int height;
  int x;
  int y;
  int top;
  int bottom;
  int right;
  int left;
  int borderThickness;
  Color border, color;

public:
  Object(int width, int height);
  Object(int width, int height, int x, int y);
  Object(int width, int height, int x, int y, const Color &color);
  Object(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness);

  void setWidth(int);
  int getWidth();

  void setHeight(int h);
  int getHeight();

  virtual void setX(int x);
  int getX();

  virtual void setY(int y);
  int getY();

  int getTop();
  int getRight();
  int getBottom();
  int getLeft();

  void setColor(Color color);
  Color getColor();

  void setBorder(Color border);
  Color getBorder();
  void setBorderThickness(int t);
  int getBorderThickness();

  void draw(HDC canvas);
};

#endif