#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

#include "components/center.h"
#include "components/colMenu.h"
#include "components/column.h"
#include "components/hpDisplay.h"
#include "components/row.h"
#include "components/rowMenu.h"
#include "components/text.h"
#include "game/camera.h"
#include "game/gameController.h"
#include "game/gui.h"
#include "game/menuStack.h"
#include "objects/boundry.h"
#include "objects/entity.h"
#include "objects/hitboxObject.h"
#include "objects/mob.h"
#include "objects/object.h"
#include "objects/triggerZone.h"
#include "objects/visibleTriggerZone.h"
#include "window/renderer.h"
#include "window/windowController.h"
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
  bool paused = false;

  // Define Input sets
  const int DEFAULT_INPUTSET = 1;
  const int DISABLED_INPUTSET = 2;
  const int DEATH_MENU_INPUTSET = 3;
  const int MAIN_MENU_INPUTSET = 4;
  const int QUIT_CONFIRM_MENU_INPUTSET = 5;

  InputHandler ih;
  ih.createFuncSet(WM_KEYDOWN, DISABLED_INPUTSET);
  ih.createFuncSet(WM_KEYUP, DISABLED_INPUTSET);
  ih.createFuncSet(WM_KEYDOWN, DEFAULT_INPUTSET);
  ih.createFuncSet(WM_KEYUP, DEFAULT_INPUTSET);
  ih.createFuncSet(WM_KEYDOWN, DEATH_MENU_INPUTSET);
  ih.createFuncSet(WM_KEYUP, DEATH_MENU_INPUTSET);
  ih.createFuncSet(WM_KEYDOWN, MAIN_MENU_INPUTSET);
  ih.createFuncSet(WM_KEYUP, MAIN_MENU_INPUTSET);
  ih.createFuncSet(WM_KEYDOWN, QUIT_CONFIRM_MENU_INPUTSET);
  ih.createFuncSet(WM_KEYUP, QUIT_CONFIRM_MENU_INPUTSET);

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

  // Define death menu options
  MenuOption respawn("respawn", []() {});
  MenuOption quit("quit", []() {});

  // Define main menu options
  MenuOption resume("resume", []() {});
  MenuOption restart("restart", []() {});

  // Define quite confirm menu options
  MenuOption quitConfirm("quit", []() {});
  MenuOption quitCancel("cancel", []() {});

  // Define GUI components
  HpDisplay hpDisplay(40, 20, white, red, &block);
  ColMenu *deathMenu = new ColMenu("You Died", {&respawn, &quit}, white, red, cyan);
  Center centeredDeathMenu(1080, 608, 0, 0, deathMenu);
  ColMenu *mainMenu = new ColMenu("Main Menu", {&resume, &restart, &quit}, white, pink, cyan);
  Center centeredMainMenu(1080, 608, 0, 0, mainMenu);
  RowMenu *quitConfirmMenu = new RowMenu("Sure you want to quit?", {&quitCancel, &quitConfirm}, white, red, cyan);
  Center centeredQuitConfirmMenu(1080, 608, 0, 0, quitConfirmMenu);
  GUI gui({&hpDisplay});
  MenuStack menuStack(&gui, &ih);

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
    paused = true;
    renderer.removeMainground(&block);
    gc.setPlayer(nullptr);
    menuStack.push(&centeredDeathMenu, DEATH_MENU_INPUTSET);

    gui.remove(&hpDisplay);
  });

  // Define inputs
  ih.setCurrentFuncSet(WM_KEYDOWN, DEFAULT_INPUTSET);
  ih.setCurrentFuncSet(WM_KEYUP, DEFAULT_INPUTSET);

  // Default inputset
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
  ih.insertFunc(WM_KEYDOWN, DEFAULT_INPUTSET, VK_ESCAPE, [&]() {
    paused = true;
    menuStack.push(&centeredMainMenu, MAIN_MENU_INPUTSET);
  });

  // Main menu inputset
  ih.insertFunc(WM_KEYDOWN, MAIN_MENU_INPUTSET, VK_ESCAPE, [&]() {
    paused = false;
    mainMenu->selectFirst();
    menuStack.pop();
  });
  ih.insertFunc(WM_KEYDOWN, MAIN_MENU_INPUTSET, VK_UP, [&]() {
    mainMenu->selectPrev();
  });
  ih.insertFunc(WM_KEYDOWN, MAIN_MENU_INPUTSET, VK_DOWN, [&]() {
    mainMenu->selectNext();
  });
  ih.insertFunc(WM_KEYDOWN, MAIN_MENU_INPUTSET, VK_RETURN, [&]() {
    mainMenu->click();
  });
  ih.insertFunc(WM_KEYDOWN, MAIN_MENU_INPUTSET, VK_SPACE, [&]() {
    mainMenu->click();
  });

  // Death menu inputset
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

  // Quit confirm menu inputset
  ih.insertFunc(WM_KEYDOWN, QUIT_CONFIRM_MENU_INPUTSET, VK_LEFT, [&]() {
    quitConfirmMenu->selectPrev();
  });
  ih.insertFunc(WM_KEYDOWN, QUIT_CONFIRM_MENU_INPUTSET, VK_RIGHT, [&]() {
    quitConfirmMenu->selectNext();
  });
  ih.insertFunc(WM_KEYDOWN, QUIT_CONFIRM_MENU_INPUTSET, VK_RETURN, [&]() {
    quitConfirmMenu->click();
  });
  ih.insertFunc(WM_KEYDOWN, QUIT_CONFIRM_MENU_INPUTSET, VK_SPACE, [&]() {
    quitConfirmMenu->click();
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
    menuStack.pop();
    renderer.appendMainground(&block);
    gc.appendEntity(&block);
    paused = false;
  };

  restart.onClick = [&]() {
    cam.setX(0);
    block.setHp(3);
    block.setX(40);
    block.setY(30);
    block.setSpeedX(0);
    block.setSpeedY(0);
    block.setMovingRight(false);
    block.setMovingLeft(false);

    menuStack.pop();
    paused = false;
  };

  resume.onClick = [&]() {
    menuStack.pop();
    paused = false;
  };

  quit.onClick = [&]() {
    menuStack.push(&centeredQuitConfirmMenu, QUIT_CONFIRM_MENU_INPUTSET);
  };

  quitCancel.onClick = [&]() {
    menuStack.pop();
  };

  quitConfirm.onClick = [&]() {
    running = false;
  };

  while (running && wc.processMessages()) {
    wc.redraw();

    if (!paused)
      gc.loopTick();

    sleep_for(milliseconds(1));
  }

  return 0;
}