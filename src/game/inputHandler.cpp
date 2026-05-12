#include "game/inputHandler.h"
#include <stdexcept>
using std::invalid_argument;

InputHandler::InputHandler() {}

bool InputHandler::eventSetExists(int event) const {
  auto keyCheck = this->inputEventSets.find(event);
  return keyCheck != this->inputEventSets.end();
}
bool InputHandler::funcSetExists(int event, int set) const {
  auto eventSet = this->inputEventSets.find(event);
  if (eventSet == this->inputEventSets.end())
    return false;

  auto keyCheck = eventSet->second.find(set);
  return keyCheck != eventSet->second.end();
}
bool InputHandler::funcExists(int event, int set, int key) const {
  auto eventSet = this->inputEventSets.find(event);
  if (eventSet == this->inputEventSets.end())
    return false;

  auto funcSet = eventSet->second.find(set);
  if (funcSet == eventSet->second.end())
    return false;

  auto keyCheck = funcSet->second.find(key);
  return keyCheck != funcSet->second.end();
}

void InputHandler::setCurrentFuncSet(int event, int set) {
  if (!this->eventSetExists(event) || !this->funcSetExists(event, set))
    throw invalid_argument("Event or set not found");

  auto eventCheck = this->currentFuncSets.find(event);
  if (eventCheck == this->currentFuncSets.end())
    this->currentFuncSets.insert({event, set});
  else
    this->currentFuncSets[event] = set;
}
int InputHandler::getCurrentFuncSet(int event) {
  return this->currentFuncSets[event];
}

void InputHandler::createEventSet(int event) {
  this->inputEventSets[event];
}

void InputHandler::createFuncSet(int event, int set) {
  this->inputEventSets[event][set];
}

void InputHandler::insertFunc(int event, int set, int key, InputFunction func) {
  if (this->funcExists(event, set, key))
    this->inputEventSets[event][set][key] = func;
  else
    this->inputEventSets[event][set].insert({key, func});
}

InputFunction InputHandler::getCurrentFunc(int event, int key) {
  auto currentSet = this->currentFuncSets.find(event);

  if (currentSet == this->currentFuncSets.end())
    throw invalid_argument("Current FuncSet not found");

  if (!this->funcExists(event, currentSet->second, key))
    throw invalid_argument("Key not found for this event");

  return this->inputEventSets[event][currentSet->second][key];
}
