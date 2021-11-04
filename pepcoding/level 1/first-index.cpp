// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/recursion-in-arrays/first-index-official/ojquestion

#include<iostream>
using namespace std;

int firstIndex(int arr[], int idx, int x, int n){
    if(arr[idx] == x) return idx;
    if(idx == n) return -1; 
    firstIndex(arr, idx + 1, x, n);
    
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = firstIndex(arr, 0, d, n);
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
3
*/