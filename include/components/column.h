#pragma once

#ifndef COLUMN_H
#define COLUMN_H

#include "components/component.h"
#include <vector>
using std::vector;

class Color;

class Column : public Component {
private:
  int gap;
  vector<Component *> children;

public:
  Column(int x, int y, Color color, vector<Component *> children);
  Column(int x, int y, Color color, vector<Component *> children, int gap);
  ~Column();

  void updateHeight() override;
  void updateWidth() override;

  void setGap(int gap);
  int getGap();

  void draw(HDC canvas) override;
};

#endif