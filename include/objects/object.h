#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include "objects/box.h"
#include "color.h"
#include <windows.h>

class Camera;

class Object : public Box {
private:
  int borderThickness;
  Color border, color;

public:
  Object(int width, int height, int x, int y);
  Object(int width, int height, int x, int y, const Color &color);
  Object(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness);

  void setColor(Color color);
  Color getColor();

  void setBorder(Color border);
  Color getBorder();
  void setBorderThickness(int t);
  int getBorderThickness();

  void draw(HDC canvas);
  void draw(HDC canvas, Camera *cam);
};

#endif