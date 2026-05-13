#pragma once

#ifndef COLUMN_H
#define COLUMN_H

#include <vector>

#include "components/component.h"
#include "components/flex.h"
using std::vector;

class Column : public Flex {
public:
  Column(vector<Component *> children);
  Column(vector<Component *> children, int gap);
  Column(int x, int y, vector<Component *> children);
  Column(int x, int y, vector<Component *> children, int gap);

  void updateHeight() override;
  void updateWidth() override;

  void draw(HDC canvas) override;
};

#endif