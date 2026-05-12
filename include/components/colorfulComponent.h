#pragma once

#ifndef COLORFUL_COMPONENT_H
#define COLORFUL_COMPONENT_H

#include "components/component.h"
#include "objects/color.h"

class ColorfulComponent : public Component {
private:
  Color color;

public:
  ColorfulComponent(int x, int y, Color &color);

  void setColor(Color &color);
  Color &getColor();
};

#endif