// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/recursion-in-arrays/last-index-official/ojquestion

#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    if(idx == n ) return -1;
    int res = lastIndex(arr, idx + 1, x, n);
    if ( res > -1 && res < n) return res;
    if(arr[idx] == x) return idx;
    return res;
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
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
4
*/