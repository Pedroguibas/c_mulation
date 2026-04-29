#pragma once

#ifndef OBJECT_LIST_H
#define OBJECT_LIST_H

#include "object.h"

class ObjectListNode {
private:
  Object *data;
  ObjectListNode *next;

public:
  ObjectListNode(Object *obj);

  ObjectListNode *getNext();
  Object *getData();
  void setNext(ObjectListNode *node);
};

class ObjectList {
private:
  ObjectListNode *start;
  ObjectListNode *current;
  ObjectListNode *end;

public:
  ObjectList();
  ObjectList(Object *obj);
  ~ObjectList();

  bool getNext();

  Object *getData();
  void append(Object *obj);

  void backToStart();
};

#endif