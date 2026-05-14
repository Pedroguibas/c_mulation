#pragma once

#ifndef MENU_H
#define MENU_H

#include <functional>
#include <string>
#include <vector>

#include "components/colorfulComponent.h"
#include "components/column.h"
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
  Color &titleColor;
  Color &selectedColor;
  Column *col;

public:
  Menu(string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor);
  ~Menu();

  int getSelected();
  virtual void selectFirst();
  virtual void selectPrev();
  virtual void selectNext();
  void click();

  Column *getMainCol();

  Color &getTitleColor();
  Color &getSelectedColor();

  void setX(int x) override;
  void setY(int y) override;

  void draw(HDC canvas) override;
};

#endif