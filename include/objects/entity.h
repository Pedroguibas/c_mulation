#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "objects/hitboxObject.h"
#include <chrono>
#include <cmath>
using std::max;
using std::min;
using std::chrono::duration;
using std::chrono::steady_clock;

class Entity : public HitboxObject {
private:
  int lastX;
  int lastY;
  float speedX;
  float speedY;
  float maxSpeedX = 1000;
  float maxSpeedY = 1000;
  float drag = 3500;
  float acceleration = 30;
  float jumpSpeed = -600;
  float wallJumpSpeedX = 400;
  bool onGround;
  bool onWallLeft;
  bool onWallRight;
  bool movingLeft = false;
  bool movingRight = false;

public:
  Entity(int width, int height);
  Entity(int width, int height, int x, int y);
  Entity(int width, int height, int x, int y, const Color &color);
  Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness);
  Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeed);
  Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeedX, float maxSpeedY);

  virtual void update(float timespan);

  void setX(int x) override;
  void setY(int y) override;

  void setLastX(int x);
  int getLastX();
  void setLastY(int y);
  int getLastY();

  void setSpeedX(float speed);
  float getSpeedX();

  void setSpeedY(float speed);
  float getSpeedY();

  void setMaxSpeed(float speed);

  void setMaxSpeedX(float speed);
  float getMaxSpeedX();

  void setMaxSpeedY(float speed);
  float getMaxSpeedY();

  void setDrag(float drag);
  float getDrag();

  void setAcceleration(float acceleration);
  float getAcceleration();
  void accelerate(float span);

  void setJumpSpeed(float speed);
  float getJumpSpeed();

  void setWallJumpSpeedX(float speed);
  float getWallJumpSpeedX();

  void setOnGround(bool onGround);
  bool isOnGround();

  void setOnWallLeft(bool onWall);
  bool isOnWallLeft();
  void setOnWallRight(bool onWall);
  bool isOnWallRight();
  bool isOnWall();

  bool isMoving();
  void setMovingLeft(bool moving);
  bool isMovingLeft();
  void setMovingRight(bool moving);
  bool isMovingRight();

  void pushout(HitboxObject &obj) override;

  void jump();

  void moveLeft();
  void moveRight();

  void applyDrag(float timespan);
};

#endif