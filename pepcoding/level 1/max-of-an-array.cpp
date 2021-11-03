// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/recursion-in-arrays/max-of-an-array-official/ojquestion

#include <iostream>
using namespace std;

int max(int arr[], int idx, int n) {
  // write your code here
  if (idx == n) return -1;
  int m = max(arr, idx + 1, n);
  if (m < arr[idx]) {
    return arr[idx];
  }
  return m;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int p = max(arr, 0, n);
  cout << p << endl;
}


/*
Sample Input: 
6
15
30
40
4
11
9
Sample Output: 
40
*/