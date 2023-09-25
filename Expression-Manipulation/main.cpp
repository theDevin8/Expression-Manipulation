#include "functions.h"
#include "linkedlist.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include "ArgumentManager.h"
using namespace std;


int main(int argc, char *argv[])
{
  
  ArgumentManager am(argc, argv);
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));
  

  string input;
  linkedlist queue;
  
  while (getline(fin, input)) {
    if (input.length() != 0) {
      if(redundantParenthesis(input)){ // checks valid parenthesis
        string postfix = infixToPostfix(input); //converts to postfix
        int evaluation = evalPostfix(postfix); //evaluates postfix and will be our priority
        queue.insertNode(evaluation, input);
      }
    }
  }
  queue.print(fout);
}
