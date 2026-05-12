#include "components/menu.h"
#include "components/text.h"

MenuOption::MenuOption(string text, function<void()> onClick)
    : text(text), onClick(onClick) {
}

Menu::Menu(string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor)
    : ColorfulComponent(x, y, color), title(title), options(options), titleColor(titleColor), selectedColor(selectedColor) {
  vector<Component *> texts;
  for (auto opt : options)
    texts.push_back(new Text(opt->text, 20, 0, 0, color));

  this->col = new Column(0, 0, {new Text(this->title, 44, 0, 0, this->titleColor), new Column(0, 0, texts, 10)}, 30);
  Column *optionsCol =
      static_cast<Column *>(
          (*this->col->getChildren())[1]);

  static_cast<Text *>(
      (*optionsCol->getChildren())[this->selected])
      ->setColor(this->selectedColor);

  this->setWidth(this->col->getWidth());
  this->setHeight(this->col->getHeight());
}

Menu::~Menu() {
  delete col;
}

void Menu::selectNext() {
  Column *optionsCol =
      static_cast<Column *>(
          (*this->col->getChildren())[1]);

  static_cast<Text *>(
      (*optionsCol->getChildren())[this->selected])
      ->setColor(this->getColor());

  this->selected = (this->selected + 1) % this->options.size();

  static_cast<Text *>(
      (*optionsCol->getChildren())[this->selected])
      ->setColor(this->selectedColor);
}
void Menu::selectPrev() {
  Column *optionsCol =
      static_cast<Column *>(
          (*this->col->getChildren())[1]);

  static_cast<Text *>(
      (*optionsCol->getChildren())[this->selected])
      ->setColor(this->getColor());

  if (this->selected > 0)
    this->selected--;
  else
    this->selected = this->options.size() - 1;

  static_cast<Text *>(
      (*optionsCol->getChildren())[this->selected])
      ->setColor(this->selectedColor);
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