#include "window/windowController.h"
#include <cwchar>
#include <stdexcept>

int width = 0;
int height = 0;

LRESULT CALLBACK WindowController::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  WindowController *self = nullptr;

  if (uMsg == WM_NCCREATE) {
    CREATESTRUCT *cs = (CREATESTRUCT *)lParam;
    self = (WindowController *)cs->lpCreateParams;

    SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)self);
  } else {
    self = (WindowController *)GetWindowLongPtr(hWnd, GWLP_USERDATA);
  }
  if (self)
    switch (uMsg) {

    case WM_PAINT: {

      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hWnd, &ps);

      HDC memDC = CreateCompatibleDC(hdc);

      HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);
      SelectObject(memDC, bitmap);

      LPCWSTR txt = L"Jogo de física Básica";

      SetTextColor(memDC, RGB(0, 255, 0));
      SetBkMode(memDC, TRANSPARENT);
      TextOutW(memDC, 10, 10, txt, std::wcslen(txt));

      SetTextColor(memDC, RGB(0, 255, 255));

      self->ol->backToStart();

      do {
        HBRUSH brush = CreateSolidBrush(RGB(self->ol->getData()->getColor().getR(), self->ol->getData()->getColor().getG(), self->ol->getData()->getColor().getB()));
        HPEN pen = CreatePen(PS_SOLID, self->ol->getData()->getBorderThickness(), RGB(self->ol->getData()->getBorder().getR(), self->ol->getData()->getBorder().getG(), self->ol->getData()->getBorder().getB()));

        HBRUSH oldBrush = (HBRUSH)SelectObject(memDC, brush);
        HPEN oldPen = (HPEN)SelectObject(memDC, pen);

        Rectangle(memDC, self->ol->getData()->getLeft(), self->ol->getData()->getTop(), self->ol->getData()->getRight(), self->ol->getData()->getBottom());

        SelectObject(memDC, oldBrush);
        SelectObject(memDC, oldPen);

        DeleteObject(brush);
        DeleteObject(pen);
      } while (self->ol->getNext());

      BitBlt(hdc, 0, 0, width, height, memDC, 0, 0, SRCCOPY);

      EndPaint(hWnd, &ps);
    } break;

    case WM_CLOSE:
      DestroyWindow(hWnd);
      break;

    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

WindowController::WindowController(int w, int h, ObjectList *ol) : m_hInstance(GetModuleHandle(nullptr)) {
  width = w;
  height = h;
  this->ol = ol;

  const wchar_t *CLASS_NAME = L"Window Class";

  WNDCLASS wc = {};
  wc.lpszClassName = CLASS_NAME;
  wc.hInstance = m_hInstance;
  wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.lpfnWndProc = WindowProc;
  wc.hbrBackground = CreateSolidBrush(RGB(50, 50, 50));

  RegisterClass(&wc);

  DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

  RECT rect;
  rect.left = 500;
  rect.top = 250;
  rect.right = rect.left + width;
  rect.bottom = rect.top + height;

  AdjustWindowRect(&rect, style, false);

  m_hWnd = CreateWindowEx(
      0,
      CLASS_NAME,
      L"Física básica",
      style,
      rect.left,
      rect.top,
      rect.right - rect.left,
      rect.bottom - rect.top,
      NULL,
      NULL,
      m_hInstance,
      this);

  ShowWindow(m_hWnd, SW_SHOW);
}

WindowController::~WindowController() {
  const wchar_t *CLASS_NAME = L"Window Class";
  UnregisterClass(CLASS_NAME, m_hInstance);
}

bool WindowController::processMessages() {
  MSG msg = {};

  while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {

    if (msg.message == WM_QUIT)
      return false;

    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return true;
}

void WindowController::redraw() {
  InvalidateRect(WindowController::getm_hWnd(), NULL, FALSE);
}
