#pragma once

#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H
#define UNICODE
#define _UNICODE

#include "objects/object.h"
#include "window/inputHandler.h"
#include <vector>
#include <windows.h>
using std::vector;

class WindowController {
private:
  HINSTANCE m_hInstance;
  HWND m_hWnd;
  vector<Object *> objectList;
  InputHandler inputs;

  static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
  WindowController(int w, int h, vector<Object *> objectList, InputHandler inputs);
  ~WindowController();

  WindowController(const WindowController &) = delete;
  WindowController &operator=(const WindowController &) = delete;

  bool processMessages();

  HWND getm_hWnd() {
    return m_hWnd;
  }

  void redraw();
};

#endif