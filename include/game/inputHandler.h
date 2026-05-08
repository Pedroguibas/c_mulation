#pragma once

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <functional>
#include <unordered_map>
using std::function;
using std::unordered_map;
using InputFunction = function<void()>;
using KeyMap = unordered_map<int, InputFunction>;
using InputSet = unordered_map<int, KeyMap>;
using EventSet = unordered_map<int, InputSet>;

class InputHandler {
private:
  EventSet inputEventSets;
  unordered_map<int, int> currentFuncSets; // <event, func>

public:
  InputHandler();

  bool eventSetExists(int set) const;
  bool funcSetExists(int event, int set) const;
  bool funcExists(int event, int set, int key) const;

  void setCurrentFuncSet(int event, int set);

  void createEventSet(int event);
  void createFuncSet(int event, int set);
  void insertFunc(int event, int set, int key, InputFunction func);

  InputFunction getCurrentFunc(int event, int key);
};

#endif