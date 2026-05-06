#include "components/hpDisplay.h"
#include "components/text.h"
#include "game/camera.h"
#include "game/gameController.h"
#include "game/gui.h"
#include "objects/boundry.h"
#include "objects/entity.h"
#include "objects/hitboxObject.h"
#include "objects/mob.h"
#include "objects/object.h"
#include "window/windowController.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
using std::cin;
using std::cout;
using std::find;
using std::string;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

int main() {
  // Define Input sets 
  const int DEFAULT_KEYDOWN_IS = 1;
  const int DEFAULT_KEYUP_IS = 1;

  // Define colors
  Color bg(50, 50, 50);
  Color cyan(0, 255, 255);
  Color red(255, 0, 0);
  Color purple(255, 0, 255);
  Color white(255, 255, 255);

  // Creates objects
  HitboxObject ground(1100, 200, 540, 608, bg, cyan, 2);
  HitboxObject box(100, 400, 220, 308, bg, red, 2);
  Mob block(40, 40, 3, 40, 30, purple);

  Camera cam(60, 918, 547, 162, &block);

  block.setMaxSpeedX(500);

  // Creates lists
  vector<Object *> objectList = {&ground, &box, &block};
  vector<HitboxObject *> hitboxList = {&ground, &box, &block};
  vector<Entity *> entityList = {&block};

  // stop rendering block after it's death
  block.setOnDeath([&]() {
    for (int i = 0; i < objectList.size(); i++) {
      if (objectList[i] == &block) {
        objectList.erase(objectList.begin() + i);
        break;
      }
    }
    for (int i = 0; i < hitboxList.size(); i++) {
      if (hitboxList[i] == &block) {
        hitboxList.erase(hitboxList.begin() + i);
        break;
      }
    }
    for (int i = 0; i < entityList.size(); i++) {
      if (entityList[i] == &block) {
        entityList.erase(entityList.begin() + i);
        break;
      }
    }
  });

  // Define inputs
  InputHandler ih;
  ih.createKeyDownSet(DEFAULT_KEYDOWN_IS);
  ih.createKeyUpSet(DEFAULT_KEYUP_IS);
  ih.insertIntoKeyDownSet(DEFAULT_KEYDOWN_IS, VK_SPACE, [&]() {
                       block.jump();
                     });

  ih.insertIntoKeyDownSet(DEFAULT_KEYDOWN_IS, VK_RIGHT, [&]() {
                       block.moveRight();
                     });
  ih.insertIntoKeyDownSet(DEFAULT_KEYDOWN_IS, VK_LEFT, [&]() {
                       block.moveLeft();
                     });

  ih.insertIntoKeyUpSet(DEFAULT_KEYUP_IS, VK_RIGHT, [&]() {
                     block.setMovingLeft(false);
                   });
  ih.insertIntoKeyUpSet(DEFAULT_KEYUP_IS, VK_LEFT, [&]() {
                     block.setMovingRight(false);
                   });

  // Define GUI components
  HpDisplay hpDisplay(40, 20, white, red, &block);
  vector<Component *> components = {&hpDisplay};
  GUI gui(components);

  // Create Window and boundries
  WindowController wc(1080, 608, objectList, gui, ih, &cam);
  int boundries[4] = {-500, 1500, 608, 0};
  Boundry boundry(boundries, wc.getWidth(), wc.getHeight());

  GameController gc(objectList, hitboxList, entityList, &cam, &boundry, 1250);
  gc.setLastTick();

  while (wc.processMessages()) {
    wc.redraw();

    gc.loopTick();

    sleep_for(milliseconds(1));
  }

  return 0;
}