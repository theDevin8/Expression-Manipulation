#include "linkedlist.h"
#include <iostream>
#include <fstream>
using namespace std;
linkedlist::linkedlist() { head = nullptr; }

bool linkedlist::isEmpty() {
  if (head == nullptr)
    return true;
  return false;
}

void linkedlist::insertNode(int value, string _expression) {
  node *newnode = new node;
  newnode->val = value;
  newnode->expression = _expression;
  newnode->next = nullptr;

  if (isEmpty())
    head = newnode;
  else {
    node *cur = head;
    if (value < cur->val) {
      newnode->next = cur;
      head = newnode;
    } else {
      node *previous = nullptr;
      while (cur != nullptr && cur->val <= value) {
        previous = cur;
        cur = cur->next;
      }
      previous->next = newnode;
      newnode->next = cur;
    }
  }
}

void linkedlist::print(ofstream &fout) {
  if(head == nullptr){
    fout << "No Valid Expression";
    return;
  }
  node *cur = head;
  while (cur != nullptr) {
    fout << cur->expression << endl;
    cur = cur->next;
  }
}
linkedlist::~linkedlist() {
  node *cur = head;
  while (cur != nullptr) {
    node *temp = cur->next;
    delete cur;
    cur = temp;
  }
}