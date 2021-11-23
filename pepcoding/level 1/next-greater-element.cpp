// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/stacks-and-queues/next-greater-element-official/ojquestion

#include <bits/stdc++.h>
#include<stack>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}

vector<int> solve(vector<int> arr) {
  //write your code here
  stack<int> stk;
  int n = arr.size();
  vector<int> nge(n, -1);

  if (n == 0) return nge;
  stk.push(0);
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] <= arr[stk.top()]) {
      stk.push(i);
    }
    else {
      while (!stk.empty() && arr[stk.top()] < arr[i]) {
        nge[stk.top()] = arr[i];
        stk.pop();
      }
      stk.push(i);
    }
  }
  return nge;
}
int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>nge(n, 0);
  nge = solve(arr);
  display(nge);
  return 0;
}

/*
Sample Input: 
5
5
3
8
-2
7
Sample Output: 
8
8
-1
7
-1
*/