#include "objects/objectList.h"

ObjectListNode::ObjectListNode(Object *obj) {
  this->data = obj;
  this->next = nullptr;
}

ObjectListNode *ObjectListNode::getNext() {
  return this->next;
}

Object *ObjectListNode::getData() {
  return this->data;
}

void ObjectListNode::setNext(ObjectListNode *node) {
  this->next = node;
}

ObjectList::ObjectList() {
  this->start = nullptr;
  this->current = nullptr;
  this->end = nullptr;
}

ObjectList::ObjectList(Object *obj) {
  ObjectListNode *node = new ObjectListNode(obj);
  this->start = node;
  this->current = node;
  this->end = node;
}

ObjectList::~ObjectList() {
  ObjectListNode *node = this->start;

  while (node != nullptr) {
    ObjectListNode *next = node->getNext();
    delete node;
    node = next;
  }
}

bool ObjectList::getNext() {
  ObjectListNode *nextptr = this->current->getNext();
  if (nextptr == nullptr)
    return false;

  this->current = nextptr;
  return true;
}

Object *ObjectList::getData() {
  return this->current->getData();
}

void ObjectList::append(Object *obj) {
  ObjectListNode *newNode = new ObjectListNode(obj);
  if (this->start == nullptr) {
    this->start = newNode;
    this->current = this->start;
  } else {
    this->end->setNext(newNode);
  }

  this->end = newNode;
}

void ObjectList::backToStart() {
  this->current = this->start;
}