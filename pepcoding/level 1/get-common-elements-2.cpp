// Problem

// https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/gce2-official/ojquestion

#include<bits/stdc++.h>
using namespace std;

int main() {

  //write your code here
  int n1, n2;
  cin >> n1;

  int a1[n1];
  unordered_map<int, int> mmap;
  for (int i = 0; i < n1; i++) {
    cin >> a1[i];
    mmap[a1[i]]++;
  }
  cin >> n2;
  int a2[n2];
  for (int i = 0; i < n2; i++) {
    cin >> a2[i];
    if (mmap[a2[i]] != 0) {
      cout << a2[i] << endl;
      mmap[a2[i]]--;
    }
  }

}

/*

Sample Input : 
7
1 1 2 2 2 3 5
7
1 1 1 2 2 4 5

Sample Ouput :
1
1
2
2
5

*/