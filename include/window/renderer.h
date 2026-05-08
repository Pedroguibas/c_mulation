#pragma once

#include <vector>
using std::vector;

#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>
#include "objects/object.h"
using ObjectVec = vector<Object *>;

class Camera;
class GUI;

class Renderer {
private:
  Camera &cam;
  GUI &gui;
  ObjectVec foreground;
  ObjectVec mainground;
  ObjectVec background;

public:
  Renderer(Camera &cam, GUI &gui);
  
  void removeForeground(Object *obj);
  void removeMainground(Object *obj);
  void removeBackground(Object *obj);

  Camera &getCam();
  GUI &getGui();

  void appendForeground(Object *newObj);
  void appendForeground(ObjectVec vec);
  void appendMainground(Object *newObj);
  void appendMainground(ObjectVec vec);
  void appendBackground(Object *newObj);
  void appendBackground(ObjectVec vec);

  void renderForeground(HDC canvas);
  void renderMainground(HDC canvas);
  void renderBackground(HDC canvas);
};

#endif