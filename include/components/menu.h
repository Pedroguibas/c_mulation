#pragma once

#ifndef MENU_H
#define MENU_H

#include "components/colorfulComponent.h"
#include "components/column.h"
#include <functional>
#include <string>
#include <vector>
using std::function;
using std::string;
using std::vector;

class MenuOption {
public:
  MenuOption(string text, function<void()> onClick);
  function<void()> onClick;
  string text;
};

class Menu : public ColorfulComponent {
private:
  string title;
  int selected = 0;
  vector<MenuOption *> options;
  Column *col;
  Color &titleColor;
  Color &selectedColor;

public:
  Menu(string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor);
  ~Menu();

  void selectPrev();
  void selectNext();
  void click();

  void setX(int x) override;
  void setY(int y) override;

  void draw(HDC canvas) override;
};

#endif