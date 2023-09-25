#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

struct node{
    int val;
    string expression;
    node* next;
};

class linkedlist{
private: 
    node* head;
public:
    linkedlist();
    ~linkedlist();
    bool isEmpty();
    void insertNode(int value, string _expression);
    void print(ofstream &fout);
};

#endif