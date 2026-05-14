#pragma once

#ifndef ROW_MENU
#define ROW_MENU

#include "components/menu.h"

class Row;

class RowMenu : public Menu {
private:
  Row *optionsContainer;

public:
  RowMenu(string title, vector<MenuOption *> options, Color &color, Color &titleColor, Color &selectedColor);
  RowMenu(
      string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor);

  void selectFirst() override;
  void selectPrev() override;
  void selectNext() override;
};

#endif