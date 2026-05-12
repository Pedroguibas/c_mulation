#include "components/colorfulComponent.h"

ColorfulComponent::ColorfulComponent(int x, int y, Color &color)
    : Component(x, y), color(color) {}

void ColorfulComponent::setColor(Color &color) {
  this->color = color;
}
Color &ColorfulComponent::getColor() {
  return this->color;
}