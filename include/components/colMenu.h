#pragma once

#ifndef COL_MENU_H
#define COL_MENU_H

#include "components/menu.h"

class ColMenu : public Menu {
private:
  Column *optionsContainer;

public:
  ColMenu(string title, vector<MenuOption *> options, Color &color, Color &titleColor, Color &selectedColor);
  ColMenu(
      string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor);

  void selectFirst() override;
  void selectPrev() override;
  void selectNext() override;
};

#endif