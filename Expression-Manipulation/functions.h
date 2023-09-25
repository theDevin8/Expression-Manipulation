#include <iostream>
#include <stack>
using namespace std;

//PRIORITY FOR INFIX TO POSTFIX
int prio(char c) {
  if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}
//INFIX TO POSTFIX FUNCTION
string infixToPostfix(string exp) {
  stack<char> myStack;
  string postfix;
  for (int i=0; i<exp.length(); i++) {
    if (isdigit(exp[i]))
      postfix += exp[i];

    else if (exp[i] == '('|| exp[i]== '{'|| exp[i] == '[')
      myStack.push(exp[i]);

    else if (exp[i] == ')'|| exp[i]== '}'|| exp[i] == ']') {
      if(exp[i] == ')'){
        while (myStack.top() != '(' ) {
          postfix += myStack.top();
          myStack.pop();
        }
        myStack.pop();
      }
      else if(exp[i] == ']')
      {
        while(myStack.top() != '[' )
        {
          postfix += myStack.top();
          myStack.pop();
        }
        myStack.pop();
      }
      else if(myStack.top() != '}')
      {
        while(myStack.top() != '{')
        {
          postfix += myStack.top();
          myStack.pop();
        }
        myStack.pop();
      }  
    }

    else {
      while (!myStack.empty() && prio(exp[i]) <= prio(myStack.top())) {
          postfix += myStack.top();
          myStack.pop();
      }
      myStack.push(exp[i]);
    }
  }

  while (!myStack.empty()) {
    postfix += myStack.top();
    myStack.pop();
  }
 
  return postfix;
}
//EVALUATION OF POSTFIX
int evalPostfix(string exp)
{
    stack<int> myStack;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            myStack.push(exp[i] - '0'); // turns string into char
        }
        else if(exp[i] != ' ')
        {
            
            int val1 = myStack.top();
            myStack.pop();
            int val2 = myStack.top();
            myStack.pop();
            switch (exp[i])
            {
            case '*':
                myStack.push(val2 * val1);
                break;
            case '/':
                myStack.push(val2 / val1);
                break;
            case '+':
                myStack.push(val2 + val1);
                break;
            case '-':
                myStack.push(val2 - val1);
                break;
            }
            
        }
    }
    return myStack.top();
}
//DETERMINING IF VALID PARENTHESIS
bool validParenthesis(string exp)
{
    stack<char> mystack;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            mystack.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (mystack.empty() || mystack.top() != '(')
            {
                return false;
            }
            mystack.pop();
        }
        else if (exp[i] == ']')
        {
            if (mystack.empty() || mystack.top() != '[')
            {
                return false;
            }
            mystack.pop();
        }
        else if (exp[i] == '}')
        {
            if (mystack.empty() || mystack.top() != '{')
            {
                return false;
            }
            mystack.pop();
        }
    }
    return mystack.empty();
}
//REDUNDANT PARENTHESIS
bool closedParenthesis(char a){
  if(a == ')' || a == '}' || a == ']')
    return true;
  return false;
}
bool openParenthesis(char a){
  if(a == '(' || a == '{' || a == '[')
    return true;
  return false;
}

bool redundantParenthesis(string str){
  if(validParenthesis(str)){
    stack<char> s;
    for(int i =0; i < str.length(); i++){
      char c = str.at(i);
      if(closedParenthesis(c)){
        if(s.empty())
          return false;
        else if(openParenthesis(s.top())){
          return false;
        }
        else{
          while(!openParenthesis(s.top()) && !s.empty())
            s.pop();
          s.pop();
        }
      }else{
        s.push(c);
      }
    }
    return true;
  }
  return false;
}