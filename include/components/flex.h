#pragma once

#ifndef FLEX_H
#define FLEX_H

#include <vector>

#include "components/component.h"
using std::vector;

class Flex : public Component {
private:
  int gap;
  vector<Component *> children;

public:
  Flex(vector<Component *> children);
  Flex(vector<Component *> children, int gap);
  Flex(int x, int y, vector<Component *> children);
  Flex(int x, int y, vector<Component *> children, int gap);
  ~Flex();

  void setY(int y) override;
  void setX(int x) override;

  void setGap(int gap);
  int getGap();

  vector<Component *> *getChildren();
  void appendChild(Component *comp);
  void removeChild(Component *comp);
};

#endif