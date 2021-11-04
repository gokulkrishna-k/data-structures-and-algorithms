// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/recursion-in-arrays/all-indices-official/ojquestion

#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
    vector<int> res;
    if(idx == arr.size()) return res;
     
     res = allIndex(arr, idx + 1, data, count);
   
   if(arr[idx] == data ) {
        res.insert(res.begin(), idx);
        return res;
    }
    
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans) cout << ele << endl;

  return 0;
}

/*
Sample Input: 
6
15
11
40
4
4
9
4
Sample Output: 
3
4
*/