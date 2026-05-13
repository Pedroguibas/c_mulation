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
  HDC hdc = GetDC(NULL);

  HFONT oldFont = (HFONT)SelectObject(hdc, this->font);

  SIZE size;
  GetTextExtentPoint32W(
      hdc,
      this->renderText.c_str(),
      (int)this->renderText.length(),
      &size);

  this->setWidth(size.cx);

  SelectObject(hdc, oldFont);
  ReleaseDC(NULL, hdc);
}
void Text::updateHeight() {
  HDC hdc = GetDC(NULL);

  HFONT oldFont = (HFONT)SelectObject(hdc, this->font);

  TEXTMETRIC tm;
  GetTextMetrics(hdc, &tm);

  this->setHeight(tm.tmHeight);

  SelectObject(hdc, oldFont);
  ReleaseDC(NULL, hdc);
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

  if (this->font != NULL)
    DeleteObject(this->font);

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

  this->updateHeight();
  this->updateWidth();
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
