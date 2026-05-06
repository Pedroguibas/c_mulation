#include "window/inputHandler.h"
#include <stdexcept>
using std::invalid_argument;

InputHandler::InputHandler() {}

bool InputHandler::keyDownSetExists(int set) {
  auto keyCheck = this->keyDownSets.find(set);
  return keyCheck == this->keyDownSets.end();
}

bool InputHandler::eventSetExists(int event) {
  auto keyCheck = this->inputEventSets.find(event);
}
bool InputHandler::funcSetExists(int event, int set) {

}
bool InputHandler::funcExists(int event, int set, int key) {

}


  void InputHandler::setCurrentKeyDown(int key) {
    if (this->keyDownSetExists(key))
      this->currentKeyDown = key;
    else
      throw invalid_argument("Key not found");
    }
    void InputHandler::setCurrentKeyUp(int key) {
      if (this->keyUpSetExists(key))
        this->currentKeyUp = key;
      else
        throw invalid_argument("Key not found");
  }

  void InputHandler::createKeyDownSet(int key) {
    if (this->keyDownSetExists(key))
      throw invalid_argument("key already exists");

    unordered_map<int, function<void()>> newSet;
    
    this->keyDownSets.insert({key, newSet});
  }
  void InputHandler::insertIntoKeyDownSet(int set, int key, function<void()>func) {
    if (!this->keyDownSetExists(set))
      throw invalid_argument("Set not found");
    
    if (this->keyDownFuncExists(set, key))
      throw invalid_argument("Key already in use");

    this->keyDownSets[set].insert({key, func});
  }

  void InputHandler::createKeyUpSet(int key) {
    if (this->keyUpSetExists(key))
      throw std::invalid_argument("key already exists");
    
    unordered_map<int, function<void()>> newSet;

    this->keyUpSets.insert({key, newSet});
  }
  void InputHandler::insertIntoKeyUpSet(int set, int key, function<void()>func) {
    if (!this->keyUpSetExists(set))
      throw invalid_argument("Set not found");
    
    if (this->keyUpFuncExists(set, key))
      throw invalid_argument("Key already in use");

    this->keyUpSets[set].insert({key, func});
  }

  unordered_map<int, function<void()>> *InputHandler::getCurrentKeyDown()
  unordered_map<int, function<void()>> *InputHandler::getCurrentKeyUp();


