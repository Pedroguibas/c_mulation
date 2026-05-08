#pragma once

#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H
#define UNICODE
#define _UNICODE

#include "game/camera.h"
#include "game/inputHandler.h"
#include "objects/object.h"
#include <vector>
#include <windows.h>
using std::vector;

class GUI;
class Renderer;

class WindowController {
private:
  HINSTANCE m_hInstance;
  HWND m_hWnd;
  Renderer &renderer;
  InputHandler &inputs;
  int width;
  int height;
  GUI &gui;

  static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
  WindowController(int w, int h, Renderer &renderer, GUI &gui, InputHandler &inputs);
  ~WindowController();

  WindowController(const WindowController &) = delete;
  WindowController &operator=(const WindowController &) = delete;

  bool processMessages();

  void setWidth(int w);
  int getWidth();
  void setHeight(int h);
  int getHeight();

  HWND getm_hWnd() {
    return m_hWnd;
  }

  void redraw();
};

#endif