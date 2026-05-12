#include "components/text.h"
#include "objects/color.h"
#include <cmath>
using std::wstring;

Text::Text(string content, int fontSize, int x, int y, Color &color)
    : content(content), ColorfulComponent(x, y, color) {
  this->renderText = this->utf8ToUtf16(content);
  this->setFontSize(fontSize);
}
Text::~Text() {
  DeleteObject(this->font);
}

void Text::updateWidth() {
  this->setWidth(this->fontSize * 0.55 * this->content.length());
}
void Text::updateHeight() {
  this->setHeight(this->fontSize);
}

void Text::setContent(string content) {
  this->content = content;
  this->renderText = this->utf8ToUtf16(content);
}
string Text::getContent() {
  return this->content;
}

void Text::setFontSize(int size) {
  this->fontSize = size;
  this->updateHeight();
  this->updateWidth();

  this->font = CreateFontW(
      this->fontSize,
      0,
      0, 0,
      FW_NORMAL,
      FALSE, FALSE, FALSE,
      DEFAULT_CHARSET,
      OUT_DEFAULT_PRECIS,
      CLIP_DEFAULT_PRECIS,
      CLEARTYPE_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE,
      L"Arial");
}

wstring Text::utf8ToUtf16(const string &str) {
  if (str.empty())
    return {};

  int size_needed = MultiByteToWideChar(
      CP_UTF8,
      0,
      str.c_str(),
      (int)str.size(),
      nullptr,
      0);

  if (size_needed <= 0)
    return {};

  std::wstring wstr(size_needed, 0);

  MultiByteToWideChar(
      CP_UTF8,
      0,
      str.c_str(),
      (int)str.size(),
      &wstr[0],
      size_needed);

  return wstr;
}

void Text::draw(HDC canvas) {
  auto originalColor = GetTextColor(canvas);
  auto originalBg = GetBkMode(canvas);

  HFONT oldFont = (HFONT)SelectObject(canvas, this->font);

  SetTextColor(canvas, RGB(this->getColor().getR(), this->getColor().getG(), this->getColor().getB()));
  SetBkMode(canvas, TRANSPARENT);

  TextOutW(canvas,
           this->getX(),
           this->getY(),
           this->renderText.c_str(),
           (int)this->renderText.length());

  SelectObject(canvas, oldFont);

  SetTextColor(canvas, originalColor);
  SetBkMode(canvas, originalBg);
}
