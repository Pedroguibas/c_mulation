#include "game/camera.h"
#include "game/gameController.h"
#include "objects/entity.h"
#include "objects/hitboxObject.h"
#include "objects/object.h"
#include "window/windowController.h"
#include <chrono>
#include <iostream>
#include <thread>
using std::cin;
using std::cout;
using std::string;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

int main() {
  Color bg(50, 50, 50);
  Color cyan(0, 255, 255);
  Color red(255, 0, 0);
  Color purple(255, 0, 255);

  HitboxObject ground(1100, 200, 540, 608, bg, cyan, 2);
  HitboxObject box(100, 400, 220, 308, bg, red, 2);
  Entity block(40, 40, 540, 30, purple);

  Camera cam(60, 918, 547, 162, &block);

  block.setMaxSpeedX(500);

  vector<Object *> objectList = {&ground, &box, &block};
  vector<HitboxObject *> hitboxList = {&ground, &box, &block};
  vector<Entity *> entityList = {&block};

  InputHandler ih;
  ih.keyDown.insert({VK_SPACE, [&]() {
                       block.jump();
                     }});

  ih.keyDown.insert({VK_RIGHT, [&]() {
                       block.moveRight();
                     }});
  ih.keyDown.insert({VK_LEFT, [&]() {
                       block.moveLeft();
                     }});

  ih.keyUp.insert({VK_RIGHT, [&]() {
                     block.setMovingLeft(false);
                   }});
  ih.keyUp.insert({VK_LEFT, [&]() {
                     block.setMovingRight(false);
                   }});

  WindowController wc(1080, 608, objectList, ih, &cam);

  GameController gc(objectList, hitboxList, entityList, &cam, 1250);
  gc.setLastTick();

  while (wc.processMessages()) {
    wc.redraw();

    gc.loopTick();

    sleep_for(milliseconds(1));
  }

  return 0;
}