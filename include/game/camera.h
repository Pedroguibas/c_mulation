#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "objects/entity.h"

class Camera {

private:
  int topLimit;
  int rightLimit;
  int bottomLimit;
  int leftLimit;
  int x;
  int y;
  Entity *focusEnt;

public:
  Camera(int topLimit, int rightLimit, int bottomLimit, int leftLimit, Entity *ent);

  void setX(int x);
  int getX();
  void setY(int y);
  int getY();

  void setTopLimit(int limit);
  int getTopLimit();
  void setRightLimit(int limit);
  int getRightLimit();
  void setBottomLimit(int limit);
  int getBottomLimit();
  void setLeftLimit(int limit);
  int getLeftLimit();

  void update();
};

#endif