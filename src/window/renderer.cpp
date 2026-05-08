#include "window/renderer.h"
#include "game/camera.h"
#include "game/gui.h"
#include <algorithm>
using std::find;

Renderer::Renderer(Camera &cam, GUI &gui) : cam(cam), gui(gui) {}

void Renderer::appendForeground(Object *newObj) {
  for (Object *obj : this->foreground)
    if (obj == newObj)
      return;

  this->foreground.push_back(newObj);
}
void Renderer::appendForeground(ObjectVec vec) {
  for (Object *obj : vec)
    this->appendForeground(obj);
}
void Renderer::appendMainground(Object *newObj) {
  for (Object *obj : this->mainground)
    if (obj == newObj)
      return;

  this->mainground.push_back(newObj);
}
void Renderer::appendMainground(ObjectVec vec) {
  for (Object *obj : vec)
    this->appendMainground(obj);
}
void Renderer::appendBackground(Object *newObj) {
  for (Object *obj : this->background)
    if (obj == newObj)
      return;

  this->background.push_back(newObj);
}
void Renderer::appendBackground(ObjectVec vec) {
  for (Object *obj : vec)
    this->appendBackground(obj);
}

void Renderer::removeForeground(Object *obj) {
  auto idx = find(this->foreground.begin(), this->foreground.end(), obj);
  if (idx != this->foreground.end())
    this->foreground.erase(idx);
}
void Renderer::removeMainground(Object *obj) {
  auto idx = find(this->mainground.begin(), this->mainground.end(), obj);
    if (idx != this->mainground.end())
      this->mainground.erase(idx);
}
void Renderer::removeBackground(Object *obj) {
  auto idx = find(this->mainground.begin(), this->mainground.end(), obj);
    if (idx != this->mainground.end())
      this->mainground.erase(idx);
}

void Renderer::renderForeground(HDC canvas) {
  for (Object *obj : this->foreground)
    obj->draw(canvas, this->cam);
}
void Renderer::renderMainground(HDC canvas) {
  for (Object *obj : this->mainground)
    obj->draw(canvas, this->cam);
}
void Renderer::renderBackground(HDC canvas) {
  for (Object *obj : this->background)
    obj->draw(canvas, this->cam);
}

Camera &Renderer::getCam() {
  return this->cam;
}
GUI &Renderer::getGui() {
  return this->gui;
}