#pragma once

#include <vector>
using std::vector;

#ifndef RENDERER_H
#define RENDERER_H
using ObjectVec = vector<Object &>;

class Object;

class Renderer {
private:
  ObjectVec foreground;
  ObjectVec mainground;
  ObjectVec background;

public:
  Renderer();
  Renderer(ObjectVec background, ObjectVec mainground, ObjectVec foreground);

  void copyForeground(ObjectVec fg);
  void copyMainground(ObjectVec mg);
  void copyBackground(ObjectVec bg);

  void renderForeground();
  void renderMainground();
  void renderBackground();
};

#endif