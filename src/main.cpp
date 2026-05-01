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
  Entity block(40, 40, 540, 30, purple);

  block.setSpeedY(10.7);

  vector<Object *> objectList = {&ground, &block};
  vector<HitboxObject *> hitboxList = {&ground, &block};
  vector<Entity *> entityList = {&block};

  InputHandler ih;
  ih.keyDown.insert({VK_SPACE, [&]() {
                       block.setY(30);
                     }});

  WindowController wc(1080, 608, objectList, ih);

  GameController gc(objectList, hitboxList, entityList, 1250);

  while (wc.processMessages()) {
    wc.redraw();

    gc.loopTick();

    sleep_for(milliseconds(5));
  }

  return 0;
}