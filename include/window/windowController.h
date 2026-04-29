#pragma once
#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H
#define UNICODE
#define _UNICODE

#include "objects/objectList.h"
#include <windows.h>

class WindowController {
private:
  HINSTANCE m_hInstance;
  HWND m_hWnd;
  ObjectList *ol;

  static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
  WindowController(int w, int h, ObjectList *ol);
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