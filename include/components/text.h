#pragma once

#ifndef TEXT_H
#define TEXT_H

#include "components/component.h"
#include <string>
using std::string;

class Text : public Component {
private:
  string content;

public:
  Text(string content, int x, int y, Color &color);

  void setContent(string content);
  string getContent();
};

#endif