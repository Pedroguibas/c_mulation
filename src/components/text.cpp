#include "components/text.h"
#include "objects/color.h"
using std::wstring;

Text::Text(string content, int fontSize, int x, int y, Color &color)
    : content(content), Component(x, y, color) {
  this->renderText = this->utf8ToUtf16(content);
  this->setFontSize(fontSize);
}
Text::~Text() {
  DeleteObject(this->font);
}

void Text::setContent(string content) {
  this->content = content;
  this->renderText = this->utf8ToUtf16(content);
  this->width = this->fontSize * 0.6 * content.length();
}
string Text::getContent() {
  return this->content;
}

void Text::setFontSize(int size) {
  this->fontSize = size;
  this->width = size * 0.6 * this->content.length();

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

float Text::getWidth() {
  return this->width;
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
