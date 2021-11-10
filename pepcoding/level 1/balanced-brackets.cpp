// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/stacks-and-queues/balanced-brackets-official/ojquestion

#include <bits/stdc++.h>
#include<stack>
using namespace std;

bool isOpenBracket(char c) {
  return c == '{' || c == '[' || c == '(';
}

bool isCloseBracket(char c) {
  return c == '}' || c == ']' || c == ')';
}

bool isMatch(char open, char close) {
  if (open == '{') {
    return close == '}';
  }
  else if (open == '[') {
    return close == ']';
  }
  else if (open == '(') {
    return close == ')';
  }
}

bool isBalanced(string str) {
  stack<char> mySt;

  for (int i = 0; i < str.length(); i++) {
    if (isCloseBracket(str[i])) {
      if (mySt.empty()) return false;
      if (isMatch(mySt.top(), str[i])) {
        mySt.pop();
      }
      else {
        return false;
      }
    }
    if (isOpenBracket(str[i])) {
      mySt.push(str[i]);
    }
  }

  if (mySt.empty()) return true;

  return false;
}

int main(int argc, char** argv) {
  //write your code
  string str ;
  getline(cin, str);

  if (isBalanced(str)) {
    cout << "true";
  }
  else {
    cout << "false";
  }
  return 0;
}

/*
Sample Input: 
[(a + b) + {(c + d) * (e / f)}]
Sample Output: 
true
*/