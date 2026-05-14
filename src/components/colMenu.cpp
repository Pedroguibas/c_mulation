#include "components/colMenu.h"

#include "components/text.h"

ColMenu::ColMenu(string title, vector<MenuOption *> options, Color &color, Color &titleColor, Color &selectedColor)
    : Menu(title, options, 0, 0, color, titleColor, selectedColor) {
  this->optionsContainer = new Column({}, 10);
  for (auto opt : options) this->optionsContainer->appendChild(new Text(opt->text, 20, 0, 0, color));
  this->getMainCol()->appendChild(this->optionsContainer);

  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])
      ->setColor(this->getSelectedColor());

  this->setWidth(this->getMainCol()->getWidth());
  this->setHeight(this->getMainCol()->getHeight());
}
ColMenu::ColMenu(
    string title, vector<MenuOption *> options, int x, int y, Color &color, Color &titleColor, Color &selectedColor)
    : Menu(title, options, x, y, color, titleColor, selectedColor) {
  this->optionsContainer = new Column({}, 10);
  for (auto opt : options) this->optionsContainer->appendChild(new Text(opt->text, 20, 0, 0, color));
  this->getMainCol()->appendChild(this->optionsContainer);

  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])
      ->setColor(this->getSelectedColor());

  this->setWidth(this->getMainCol()->getWidth());
  this->setHeight(this->getMainCol()->getHeight());
}

void ColMenu::selectFirst() {
  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])->setColor(this->getColor());

  Menu::selectFirst();

  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])
      ->setColor(this->getSelectedColor());
}
void ColMenu::selectNext() {
  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])->setColor(this->getColor());

  Menu::selectNext();

  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])
      ->setColor(this->getSelectedColor());
}

void ColMenu::selectPrev() {
  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])->setColor(this->getColor());

  Menu::selectPrev();

  static_cast<Text *>((*this->optionsContainer->getChildren())[this->getSelected()])
      ->setColor(this->getSelectedColor());
}