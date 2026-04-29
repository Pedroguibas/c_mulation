#ifndef COLOR_H
#define COLOR_H

class Color {
private:
  int r, g, b;

public:
  Color(int r, int g, int b);

  void setR(int r);
  int getR();

  void setG(int g);
  int getG();

  void setB(int b);
  int getB();
};

#endif