#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <functional>
#include <unordered_map>
using std::function;
using std::unordered_map;

class InputHandler {
public:
  unordered_map<int, function<void()>> keyDown;
  InputHandler() {}
};

#endif