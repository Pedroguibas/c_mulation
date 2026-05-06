#pragma once

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <functional>
#include <unordered_map>
using std::function;
using std::unordered_map;

class InputHandler {
private:
  unordered_map<int, unordered_map<int, unordered_map<int, function<void()>>>> inputEventSets;
  unordered_map<int, int> currentFuncSets; // <event, func>

public:
  InputHandler();

  bool eventSetExists(int set);
  bool funcSetExists(int event, int set);
  bool funcExists(int event, int set, int key);

  void setCurrentFuncSet(int event, int key);

  void createFuncSet(int event, int set);
  void insertFunc(int event, int set, int key, function<void()>func);

  function<void()> getCurrentFunc();
};

#endif