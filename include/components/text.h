#pragma once

#ifndef TEXT_H
#define TEXT_H

#include "components/component.h"
#include <string>
using std::string;
using std::wstring;

class Text : public Component {
protected:
  string content;
  int fontSize;
  wstring renderText;
  HFONT font;
  
  
public:
  Text(string content, int fontSize, int x, int y, Color &color);
  ~Text();
  
  void setContent(string content);
  string getContent();
  
  wstring utf8ToUtf16(const string &str);

  void updateHeight() override;
  void updateWidth() override;
  
  void setFontSize(int size);
  
  void draw(HDC canvas) override;
};

#endif