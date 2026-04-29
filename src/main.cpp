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


  HitboxObject obj1(30, 30, 205, 150, c1, c2, 2);
  HitboxObject obj2(30, 30, 205, 304, c2, c1, 2);

  ObjectList ol(&obj1);
  ol.append(&obj2);

  WindowController wc(1080, 608, &ol);

  bool running = true;

  while (wc.processMessages()) {
    wc.redraw();

    obj1.setY(obj1.getY() + 4);

    obj1.colide(obj2);

    sleep_for(milliseconds(30));
  }

  return 0;
}