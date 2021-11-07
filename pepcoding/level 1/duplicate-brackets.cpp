// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/stacks-and-queues/duplicate-brackets-official/ojquestion

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOpenBracket(char c) {
  return c == '(' || c == '{' || c == '[';

}

bool isCloseBracket(char c) {
  return c == ')' || c == '}' || c == ']';

}

int main() {
  string str;
  getline(cin, str);
  stack<char> stk;

  bool isDuplicate = false;
  for (int i = 0; i < str.length(); i++) {
    if (isCloseBracket(str[i])) {
      if (isOpenBracket(stk.top())) {
        isDuplicate = true;
        break;
      }
      while (stk.top() != '(') {
        stk.pop();
      }
      stk.pop();
    }
    else {
      stk.push(str[i]);
    }
  }

  if (isDuplicate)
    cout << "true";
  else
    cout << "false";

}

/*
Sample Input: 
(a + b) + ((c + d))
Sample Output: 
true
*/