#pragma once

#ifndef GUI_H
#define GUI_H

#include <vector>
using std::vector;

class Object;

class GUI {
private:
  vector<Object*> components;
  
public:
  GUI(vector<Object*> components);

  vector<Object*>* getComponents();


};

#endif