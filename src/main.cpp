#include "components/center.h"
#include "components/column.h"
#include "components/hpDisplay.h"
#include "components/menu.h"
#include "components/text.h"
#include "game/camera.h"
#include "game/gameController.h"
#include "game/gui.h"
#include "objects/boundry.h"
#include "objects/entity.h"
#include "objects/hitboxObject.h"
#include "objects/mob.h"
#include "objects/object.h"
#include "objects/triggerZone.h"
#include "objects/visibleTriggerZone.h"
#include "window/renderer.h"
#include "window/windowController.h"
#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using std::cout;
using std::endl;
using std::find;
using std::function;
using std::string;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

void setTimeout(int ms, function<void()> func) {
  std::thread([=]() {
    sleep_for(milliseconds(ms));
    func();
  }).detach();
}

int main() {
  // Declare stopper;
  bool running = true;

  // Define Input sets
  const int DEFAULT_INPUTSET = 1;
  const int DISABLED_INPUTSET = 2;
  const int DEATH_MENU_INPUTSET = 3;
  InputHandler ih;
  ih.createFuncSet(WM_KEYDOWN, DISABLED_INPUTSET);
  ih.createFuncSet(WM_KEYUP, DISABLED_INPUTSET);
  ih.createFuncSet(WM_KEYDOWN, DEFAULT_INPUTSET);
  ih.createFuncSet(WM_KEYUP, DEFAULT_INPUTSET);
  ih.createFuncSet(WM_KEYDOWN, DEATH_MENU_INPUTSET);
  ih.createFuncSet(WM_KEYUP, DEATH_MENU_INPUTSET);

  // Define colors
  Color bg(50, 50, 50);
  Color cyan(0, 255, 255);
  Color red(255, 0, 0);
  Color pink(255, 0, 255);
  Color white(255, 255, 255);

  // Creates objects
  HitboxObject ground(1100, 200, 540, 608, bg, cyan, 2);
  HitboxObject box(100, 400, 220, 308, bg, red, 2);
  Mob block(40, 40, 3, 40, 30, pink);

  block.setMaxSpeedX(500);

  // Creates lists
  vector<Object *> objectList = {&ground, &box, &block};
  vector<HitboxObject *> hitboxList = {&ground, &box};
  VisibleTriggerZone<Mob> takeDmgTrigger(3000, 40, 1500, 608, red, false, {&block}, [&](Mob *ent) {
    ent->takeDamage(1);

    if (ent->isAlive()) {
      ih.setCurrentFuncSet(WM_KEYDOWN, DISABLED_INPUTSET);
      ih.setCurrentFuncSet(WM_KEYUP, DISABLED_INPUTSET);

      ent->setSpeedX(0);
      ent->setSpeedY(0);
      ent->setX(1000);
      ent->setY(408);
      ent->setMovingRight(false);
      ent->setMovingLeft(false);

      setTimeout(500, [&]() {
        ih.setCurrentFuncSet(WM_KEYDOWN, DEFAULT_INPUTSET);
        ih.setCurrentFuncSet(WM_KEYUP, DEFAULT_INPUTSET);
      });
    }
  });

  // Define menu options
  MenuOption respawn("respawn", [&]() {});
  MenuOption quit("quit", [&]() {});

  // Define GUI components
  HpDisplay hpDisplay(40, 20, white, red, &block);
  // Center death(1080, 608, 0, 0, new Column(0, 0, {new Text("You Died", 44, 0, 0, red), new Column(0, 0, {new Text("respawn", 30, 0, 0, white), new Text("quit", 30, 0, 0, white)}, 10)}, 30));
  Menu *deathMenu = new Menu("You Died", {&respawn, &quit}, 0, 0, white, red, cyan);
  Center death(1080, 608, 0, 0, deathMenu);
  GUI gui({&hpDisplay});

  // Creates renderer
  Camera cam(60, 918, 400, 162, &block);
  Renderer renderer(cam, gui);
  renderer.appendMainground(objectList);
  renderer.appendBackground(&takeDmgTrigger);

  // Create Window and boundries
  WindowController wc(1080, 608, renderer, gui, ih);
  int boundries[4] = {-500, 1500, 608, 0};
  Boundry boundry(boundries, wc.getWidth(), wc.getHeight());

  GameController gc(&block, hitboxList, {}, {&takeDmgTrigger}, &cam, &boundry, 1250);
  gc.setLastTick();

  // stop rendering block after it's death
  block.setOnDeath([&]() {
    renderer.removeMainground(&block);
    gc.setPlayer(nullptr);
    ih.setCurrentFuncSet(WM_KEYDOWN, DEATH_MENU_INPUTSET);
    // ih.setCurrentFuncSet(WM_KEYUP, DISABLED_INPUTSET);
    gui.add(&death);
    gui.remove(&hpDisplay);
  });

  // Define inputs
  ih.setCurrentFuncSet(WM_KEYDOWN, DEFAULT_INPUTSET);
  ih.setCurrentFuncSet(WM_KEYUP, DEFAULT_INPUTSET);
  ih.insertFunc(WM_KEYDOWN, DEFAULT_INPUTSET, VK_SPACE, [&]() {
    block.jump();
  });
  ih.insertFunc(WM_KEYDOWN, DEFAULT_INPUTSET, VK_UP, [&]() {
    block.jump();
  });

  ih.insertFunc(WM_KEYDOWN, DEFAULT_INPUTSET, VK_RIGHT, [&]() {
    block.moveRight();
  });
  ih.insertFunc(WM_KEYDOWN, DEFAULT_INPUTSET, VK_LEFT, [&]() {
    block.moveLeft();
  });

  ih.insertFunc(WM_KEYUP, DEFAULT_INPUTSET, VK_RIGHT, [&]() {
    block.setMovingLeft(false);
  });
  ih.insertFunc(WM_KEYUP, DEFAULT_INPUTSET, VK_LEFT, [&]() {
    block.setMovingRight(false);
  });

  ih.insertFunc(WM_KEYDOWN, DEATH_MENU_INPUTSET, VK_UP, [&]() {
    deathMenu->selectPrev();
  });
  ih.insertFunc(WM_KEYDOWN, DEATH_MENU_INPUTSET, VK_DOWN, [&]() {
    deathMenu->selectNext();
  });
  ih.insertFunc(WM_KEYDOWN, DEATH_MENU_INPUTSET, VK_RETURN, [&]() {
    deathMenu->click();
  });
  ih.insertFunc(WM_KEYDOWN, DEATH_MENU_INPUTSET, VK_SPACE, [&]() {
    deathMenu->click();
  });

  respawn.onClick = [&]() {
    cam.setX(0);
    block.setHp(3);
    block.setX(40);
    block.setY(30);
    block.setSpeedX(0);
    block.setSpeedY(0);
    block.setMovingRight(false);
    block.setMovingLeft(false);

    gui.add(&hpDisplay);
    gui.remove(&death);
    renderer.appendMainground(&block);
    gc.appendEntity(&block);

    ih.setCurrentFuncSet(WM_KEYDOWN, DEFAULT_INPUTSET);
    ih.setCurrentFuncSet(WM_KEYUP, DEFAULT_INPUTSET);
  };

  quit.onClick = [&]() {
    running = false;
  };

  while (running && wc.processMessages()) {
    wc.redraw();

    gc.loopTick();

    sleep_for(milliseconds(1));
  }

  return 0;
}