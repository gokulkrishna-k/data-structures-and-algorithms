// Problem

// https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/gce1-official/ojquestion


#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n1, n2;
  cin >> n1;
  unordered_map<int, int> a1map;
  int arr1[n1];

  for (int i = 0; i < n1; i++) {
    cin >> arr1[i];
    a1map[arr1[i]]++;
  }
  cin >> n2;
  int arr2[n2];
  for (int i = 0; i < n2; i++) {
    cin >> arr2[i];

    // write your code here
    if (a1map[arr2[i]] != 0) {
      a1map[arr2[i]] = 0;
      cout << arr2[i] << endl;
    }

  }
}

/*
SAMPLE INPUT
9
5 5 9 8 5 5 8 0 3
18
9 7 1 0 3 6 5 9 1 1 8 0 2 4 2 9 1 5


SAMPLE OUPUT
9 
0 
3 
5 
8
*/