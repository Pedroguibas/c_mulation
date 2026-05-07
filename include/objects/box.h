#pragma once

#ifndef BOX_H
#define BOX_H

class Box {
private:
  int width;
  int height;
  int x;
  int y;
  int top;
  int bottom;
  int right;
  int left;

public:
  Box(int width, int height, int x, int y);
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
};

#endif