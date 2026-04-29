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

  Object obj1(30, 30, 115, 304);
  Object obj2(30, 30, 160, 304);
  HitboxObject obj3(30, 30, 205, 304, c1, c2, 2);

  ObjectList ol(&obj1);
  ol.append(&obj2);
  ol.append(&obj3);

  WindowController wc(1080, 608, &ol);

  bool running = true;

  while (wc.processMessages()) {
    wc.redraw();

    obj3.setY(obj3.getY() + 1);

    sleep_for(milliseconds(30));
  }

  return 0;
}