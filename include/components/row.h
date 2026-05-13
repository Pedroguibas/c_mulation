#pragma once

#ifndef ROW_H
#define ROW_H

#include "components/component.h"
#include "components/flex.h"

class Row : public Flex {
public:
  Row(vector<Component *> children);
  Row(vector<Component *> children, int gap);
  Row(int x, int y, vector<Component *> children);
  Row(int x, int y, vector<Component *> children, int gap);

  void updateHeight() override;
  void updateWidth() override;

  void draw(HDC canvas) override;
};

#endif