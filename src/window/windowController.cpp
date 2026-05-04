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

      HBRUSH bgBrush = CreateSolidBrush(RGB(50, 50, 50));
      RECT rect = {0, 0, width, height};
      FillRect(memDC, &rect, bgBrush);
      DeleteObject(bgBrush);

      LPCWSTR txt = L"C Mulation";

      SetTextColor(memDC, RGB(0, 255, 0));
      SetBkMode(memDC, TRANSPARENT);
      TextOutW(memDC, 10, 10, txt, std::wcslen(txt));

      SetTextColor(memDC, RGB(0, 255, 255));

      for (int i = 0; i < self->objectList.size(); i++) {
        self->objectList[i]->draw(memDC);
      }

      BitBlt(hdc, 0, 0, width, height, memDC, 0, 0, SRCCOPY);

      DeleteObject(bitmap);
      DeleteDC(memDC);

      EndPaint(hWnd, &ps);
    } break;

    case WM_KEYDOWN:
      if (self->inputs.keyDown.find(wParam) != self->inputs.keyDown.end())
        self->inputs.keyDown[wParam]();

      break;

    case WM_KEYUP:
      if (self->inputs.keyUp.find(wParam) != self->inputs.keyUp.end())
        self->inputs.keyUp[wParam]();

      break;

    case WM_CLOSE:
      DestroyWindow(hWnd);
      break;

    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

WindowController::WindowController(int w, int h, vector<Object *> objectList, InputHandler inputs) : m_hInstance(GetModuleHandle(nullptr)), inputs(inputs) {
  width = w;
  height = h;
  this->objectList = objectList;

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
      L"C Mulation",
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
