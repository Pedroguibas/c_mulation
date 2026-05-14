#pragma once

#ifndef MENU_STACK_H
#define MENU_STACK_H

#include <vector>
using std::vector;

class GUI;
class InputHandler;
class Component;

class MenuInfo {
public:
  MenuInfo(Component *menu, int inputsetKey, int prevInputsetKey);

  Component *menu;
  int inputsetKey;
  int prevInputsetKey;
};

class MenuStack {
private:
  vector<MenuInfo> stack;
  GUI *gui;
  InputHandler *ih;

public:
  MenuStack(GUI *gui, InputHandler *ih);

  void push(Component *menu, int inputsetKey);
  void pop();
};

#endif