#include "game/menuStack.h"

#include "components/component.h"
#include "game/gui.h"
#include "game/inputHandler.h"

MenuInfo::MenuInfo(Component *menu, int inputsetKey, int prevInputsetKey)
    : menu(menu), inputsetKey(inputsetKey), prevInputsetKey(prevInputsetKey) {}

MenuStack::MenuStack(GUI *gui, InputHandler *ih) : gui(gui), ih(ih) {}

void MenuStack::push(Component *menu, int inputsetKey) {
  if (!this->stack.empty())
    gui->remove(this->stack.back().menu);

  gui->add(menu);
  MenuInfo newMI(menu, inputsetKey, ih->getCurrentFuncSet(WM_KEYDOWN));
  this->stack.push_back(newMI);
  ih->setCurrentFuncSet(WM_KEYDOWN, inputsetKey);
  ih->setCurrentFuncSet(WM_KEYUP, inputsetKey);
}
void MenuStack::pop() {
  MenuInfo oldMI = this->stack.back();
  this->stack.pop_back();
  gui->remove(oldMI.menu);
  if (!this->stack.empty())
    gui->add(this->stack.back().menu);
  ih->setCurrentFuncSet(WM_KEYDOWN, oldMI.prevInputsetKey);
  ih->setCurrentFuncSet(WM_KEYUP, oldMI.prevInputsetKey);
}