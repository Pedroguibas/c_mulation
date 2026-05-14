#include "components/menu.h"

#include "components/text.h"

MenuOption::MenuOption(string text, function<void()> onClick) : text(text), onClick(onClick) {}

Menu::Menu(
    string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor)
    : ColorfulComponent(x, y, color),
      title(title),
      options(options),
      titleColor(titleColor),
      selectedColor(selectedColor) {
  this->col = new Column(0, 0, {new Text(this->title, 44, 0, 0, this->titleColor)}, 30);
}

Menu::~Menu() {
  delete col;
}

Column *Menu::getMainCol() {
  return this->col;
}

Color &Menu::getTitleColor() {
  return this->titleColor;
}
Color &Menu::getSelectedColor() {
  return this->selectedColor;
}

int Menu::getSelected() {
  return this->selected;
}
void Menu::selectFirst() {
  this->selected = 0;
}
void Menu::selectNext() {
  this->selected = (this->selected + 1) % this->options.size();
}
void Menu::selectPrev() {
  if (this->selected > 0)
    this->selected--;
  else
    this->selected = this->options.size() - 1;
}
void Menu::click() {
  this->options[this->selected]->onClick();
}

void Menu::draw(HDC canvas) {
  this->col->draw(canvas);
}

void Menu::setX(int x) {
  this->col->setX(x);
  Component::setX(x);
}
void Menu::setY(int y) {
  this->col->setY(y);
  Component::setY(y);
}