#include "objects/entity.h"
#include <cmath>

Entity::Entity(int width, int height) : HitboxObject(width, height) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y) : HitboxObject(width, height, x, y) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y, const Color &color) : HitboxObject(width, height, x, y, color) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness) : HitboxObject(width, height, x, y, color, border, borderThickness) {
  this->setSpeedX(0);
  this->setSpeedY(0);
}
Entity::Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeed) : HitboxObject(width, height, x, y, color, border, borderThickness) {
  this->setSpeedX(0);
  this->setSpeedY(0);
  this->setMaxSpeedX(maxSpeed);
  this->setMaxSpeedY(maxSpeed);
}
Entity::Entity(int width, int height, int x, int y, const Color &color, const Color &border, int borderThickness, float maxSpeedX, float maxSpeedY) : HitboxObject(width, height, x, y, color, border, borderThickness) {
  this->setSpeedX(0);
  this->setSpeedY(0);
  this->setMaxSpeedX(maxSpeedX);
  this->setMaxSpeedY(maxSpeedY);
}

void Entity::update(float timespan) {
  this->accelerate(timespan);
  this->applyDrag(timespan);

  this->setX(this->getX() + round(this->getSpeedX() * timespan));
  this->setY(this->getY() + round(this->getSpeedY() * timespan));
}

void Entity::setX(int x) {
  this->setLastX(this->getX());
  Object::setX(x);
}

void Entity::setY(int y) {
  this->setLastY(this->getY());
  Object::setY(y);
}

void Entity::setLastX(int x) {
  this->lastX = x;
}
int Entity::getLastX() {
  return this->lastX;
}
void Entity::setLastY(int y) {
  this->lastY = y;
}
int Entity::getLastY() {
  return this->lastY;
}

void Entity::setSpeedX(float speed) {
  if (speed > this->maxSpeedX)
    this->speedX = this->maxSpeedX;
  else if (speed < -this->maxSpeedX)
    this->speedX = -this->maxSpeedX;
  else
    this->speedX = speed;
}
float Entity::getSpeedX() {
  return this->speedX;
}

void Entity::setSpeedY(float speed) {
  if (speed > this->maxSpeedY)
    this->speedY = this->maxSpeedY;
  else if (speed < -this->maxSpeedY)
    this->speedY = -this->maxSpeedY;
  else
    this->speedY = speed;
}

float Entity::getSpeedY() {
  return this->speedY;
}

void Entity::setMaxSpeed(float speed) {
  this->setMaxSpeedX(speed);
  this->setMaxSpeedY(speed);
}

void Entity::setMaxSpeedX(float speed) {
  this->maxSpeedX = speed;
}
float Entity::getMaxSpeedX() {
  return this->maxSpeedX;
}

void Entity::setMaxSpeedY(float speed) {
  this->maxSpeedY = speed;
}
float Entity::getMaxSpeedY() {
  return this->maxSpeedY;
}

void Entity::setDrag(float drag) {
  this->drag = drag;
}
float Entity::getDrag() {
  return this->drag;
}

void Entity::setAcceleration(float acceleration) {
  this->acceleration = acceleration;
}
float Entity::getAcceleration() {
  return this->acceleration;
}
void Entity::accelerate(float span) {

  if (this->isMovingRight())
    this->setSpeedX(this->getSpeedX() + this->getAcceleration() + span);

  if (this->isMovingLeft())
    this->setSpeedX(this->getSpeedX() - this->getAcceleration() + span);
}

void Entity::setJumpSpeed(float speed) {
  if (speed > 0)
    speed *= -1;

  this->jumpSpeed = speed;
}
float Entity::getJumpSpeed() {
  return this->jumpSpeed;
}

void Entity::setWallJumpSpeedX(float speed) {
  if (speed < 0)
    speed *= -1;

  this->wallJumpSpeedX = speed;
}
float Entity::getWallJumpSpeedX() {
  return this->wallJumpSpeedX;
}

void Entity::setOnGround(bool onGround) {
  this->onGround = onGround;
}
bool Entity::isOnGround() {
  return this->onGround;
}

void Entity::setOnWallLeft(bool onWall) {
  this->onWallLeft = onWall;
}
bool Entity::isOnWallLeft() {
  return this->onWallLeft;
}
void Entity::setOnWallRight(bool onWall) {
  this->onWallRight = onWall;
}
bool Entity::isOnWallRight() {
  return this->onWallRight;
}
bool Entity::isOnWall() {
  return this->isOnWallLeft() || this->isOnWallRight();
}

void Entity::setMovingLeft(bool moving) {
  this->movingRight = false;
  this->movingLeft = moving;
}
bool Entity::isMovingLeft() {
  return this->movingLeft;
}
void Entity::setMovingRight(bool moving) {
  this->movingLeft = false;
  this->movingRight = moving;
}
bool Entity::isMovingRight() {
  return this->movingRight;
}
bool Entity::isMoving() {
  return this->isMovingLeft() || this->isMovingRight();
}

void Entity::jump() {
  if (this->isOnGround()) {
    this->setSpeedY(this->getJumpSpeed());

  } else if (this->isOnWallLeft()) {
    this->setSpeedY(this->getJumpSpeed());

    this->setSpeedX(this->getWallJumpSpeedX());
  } else if (this->isOnWallRight()) {
    this->setSpeedY(this->getJumpSpeed());

    this->setSpeedX(-this->getWallJumpSpeedX());
  }
}

void Entity::moveLeft() {
  if (!this->isMoving()) {
    this->setMovingLeft(true);
    this->setSpeedX(this->getSpeedX() - this->getAcceleration());
  }
}
void Entity::moveRight() {
  if (!this->isMoving()) {
    this->setMovingRight(true);
    this->setSpeedX(this->getSpeedX() + this->getAcceleration());
  }
}

void Entity::applyDrag(float timespan) {
  if (this->isMoving() || !this->isOnGround())
    return;

  float speed = this->getSpeedX();

  if (speed > 0) {
    if (speed - this->getDrag() * timespan < 0)
      this->setSpeedX(0);
    else
      this->setSpeedX(speed - this->getDrag() * timespan);
  } else if (speed < 0) {
    if (speed + this->getDrag() * timespan > 0)
      this->setSpeedX(0);
    else
      this->setSpeedX(speed + this->getDrag() * timespan);
  }
}

void Entity::pushout(HitboxObject &obj) {
  int xOverlap = min(this->getRight(), obj.getRight()) - max(this->getLeft(), obj.getLeft());
  int yOverlap = min(this->getBottom(), obj.getBottom()) - max(this->getTop(), obj.getTop());
  if (xOverlap < yOverlap) {
    if (this->getX() > obj.getX()) {
      this->setX(obj.getRight() + this->getWidth() / 2);

      this->setOnWallLeft(true);
    } else {
      this->setX(obj.getLeft() - this->getWidth() / 2);

      this->setOnWallRight(true);
    }

    this->setSpeedX(0);
  } else {
    if (this->getY() > obj.getY())
      this->setY(obj.getBottom() + this->getHeight() / 2);
    else {
      this->setY(obj.getTop() - this->getHeight() / 2);
      this->setSpeedY(0);
      this->setOnGround(true);
    }
  }
}