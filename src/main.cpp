#include "objects/hitboxObject.h"
#include "objects/object.h"
#include "objects/objectList.h"
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
  Color c1(0, 255, 255);
  Color c2(255, 0, 0);

  HitboxObject obj1(30, 30, 205, 304, c1, c2, 2);
  HitboxObject testT(30, 30, 205, 154, c2, c1, 2);
  HitboxObject testR(30, 30, 355, 304, c2, c1, 2);
  HitboxObject testB(30, 30, 205, 454, c2, c1, 2);
  HitboxObject testL(30, 30, 55, 304, c2, c1, 2);

  ObjectList ol(&obj1);
  ol.append(&testT);
  ol.append(&testR);
  ol.append(&testB);
  ol.append(&testL);

  WindowController wc(1080, 608, &ol);

  bool running = true;

  while (wc.processMessages()) {
    wc.redraw();

    testT.setY(testT.getY() + 4);
    testB.setY(testB.getY() - 4);
    testL.setX(testL.getX() + 4);
    testR.setX(testR.getX() - 4);

    testT.collide(obj1);
    testR.collide(obj1);
    testB.collide(obj1);
    testL.collide(obj1);

    sleep_for(milliseconds(30));
  }

  return 0;
}