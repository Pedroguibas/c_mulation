#include "components/flex.h"

#include <algorithm>
using std::find;

Flex::Flex(vector<Component *> children) : Component(0, 0), children(children), gap(0) {
  this->updateHeight();
  this->updateWidth();
}
Flex::Flex(vector<Component *> children, int gap) : Component(0, 0), children(children), gap(gap) {
  this->updateHeight();
  this->updateWidth();
}
Flex::Flex(int x, int y, vector<Component *> children) : Component(x, y), children(children), gap(0) {
  this->updateHeight();
  this->updateWidth();
}
Flex::Flex(int x, int y, vector<Component *> children, int gap) : Component(x, y), children(children), gap(gap) {
  this->updateHeight();
  this->updateWidth();
}
Flex::~Flex() {
  for (auto *comp : this->children) delete comp;
}

void Flex::setY(int y) {
  Component::setY(y);
  this->updateHeight();
  this->updateWidth();
}
void Flex::setX(int x) {
  Component::setX(x);
  this->updateHeight();
  this->updateWidth();
}

void Flex::setGap(int gap) {
  this->gap = gap;
  this->updateHeight();
  this->updateWidth();
}
int Flex::getGap() {
  return this->gap;
}

void Flex::appendChild(Component *comp) {
  auto idx = find(this->children.begin(), this->children.end(), comp);

  if (idx == this->children.end())
    this->children.push_back(comp);
}
void Flex::removeChild(Component *comp) {
  auto idx = find(this->children.begin(), this->children.end(), comp);

  if (idx != this->children.end())
    this->children.erase(idx);
}
vector<Component *> *Flex::getChildren() {
  return &this->children;
}
