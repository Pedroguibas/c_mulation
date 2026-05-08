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

class WindowController {
private:
  HINSTANCE m_hInstance;
  HWND m_hWnd;
  vector<Object *> &objectList;
  InputHandler &inputs;
  int width;
  int height;
  Camera *cam;
  GUI &gui;

  static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
  WindowController(int w, int h, vector<Object *> &objectList, GUI &gui, InputHandler &inputs);
  WindowController(int w, int h, vector<Object *> &objectList, GUI &gui, InputHandler &inputs, Camera *cam);
  ~WindowController();

  WindowController(const WindowController &) = delete;
  WindowController &operator=(const WindowController &) = delete;

  bool processMessages();

  void setWidth(int w);
  int getWidth();
  void setHeight(int h);
  int getHeight();

  void setGUI(GUI &gui);

  void setCamera(Camera *cam);

  HWND getm_hWnd() {
    return m_hWnd;
  }

  void redraw();
};

#endif