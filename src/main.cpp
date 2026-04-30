#include "objects/hitboxObject.h"
#include "objects/object.h"
#include "objects/entity.h"
#include "window/windowController.h"
#include "game/gameController.h"
#include <chrono>
#include <iostream>
#include <thread>
using std::cin;
using std::cout;
using std::string;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

int main() {
  Color c1(0, 255, 255);
  Color c2(255, 0, 0);

  HitboxObject obj1(30, 30, 205, 304, c1, c2, 2);
  Entity eT(30, 30, 205, 154, c2, c1, 2);
  Entity eR(30, 30, 355, 304, c2, c1, 2);
  Entity eB(30, 30, 205, 454, c2, c1, 2);
  Entity eL(30, 30, 55, 304, c2, c1, 2);

  eT.setSpeedY(4);
  eR.setSpeedX(-4);
  eB.setSpeedY(-4);
  eL.setSpeedX(4);

  vector<Object*> objectList = {&obj1, &eT, &eR, &eB, &eL};
  vector<HitboxObject*> hitboxList = {&obj1, &eT, &eR, &eB, &eL};
  vector<Entity *> entityList = {&eT, &eR, &eB, &eL};

  InputHandler ih;
  ih.keyDown.insert({VK_SPACE, [&]() {
                        eT.setSpeedY(eT.getSpeedY() * -1);
                        eB.setSpeedY(eB.getSpeedY() * -1);
                        eL.setSpeedX(eL.getSpeedX() * -1);
                        eR.setSpeedX(eR.getSpeedX() * -1);
                      }});

  

  WindowController wc(1080, 608, objectList, ih);

  GameController gc(objectList, hitboxList, entityList);

  while (wc.processMessages()) {
    wc.redraw();

    gc.update();

    gc.testCollisions();

    sleep_for(milliseconds(30));
  }

  return 0;
}