#pragma once

#ifndef BOUNDRY_H
#define BOUNDRY_H

class Boundry {
private:
  int windowWidth;
  int windowHeight;
  int top;
  int right;
  int bottom;
  int left;

public:
  Boundry(int *boundries, int w, int h);
  Boundry(int top, int right, int bottom, int left, int w, int h);

  void setWindowWidth(int w);
  int getWindowWidth();
  void setWindowHeight(int h);
  int getWindowHeight();

  void setTop(int top);
  int getTop();
  void setRight(int right);
  int getRight();
  void setBottom(int bottom);
  int getBottom();
  void setLeft(int left);
  int getLeft();
};

#endif