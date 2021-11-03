// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/introduction-to-recursion/power-logarithmic-official/ojquestion

#include<iostream>
using namespace std;

int powerLogarithmic(int x, int n) {
  // write your code here
  if (n <= 0) return 1;
  if (n % 2 == 0) {

    return powerLogarithmic(x, n / 2) * powerLogarithmic(x, n / 2);
  }
  else {
    return x * powerLogarithmic(x, (n - 1) / 2) * powerLogarithmic(x, (n - 1) / 2);
  }
}

int main() {
  int x, n;
  cin >> x >> n;
  cout << powerLogarithmic(x, n);
}
/*
Sample Input: 
2
5
Sample Output: 
32
*/