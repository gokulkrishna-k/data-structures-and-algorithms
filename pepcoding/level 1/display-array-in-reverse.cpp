// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/recursion-in-arrays/display-array-in-reverse/ojquestion

#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    // write your code here
    if(n == idx) return;
    display(arr , idx + 1 , n);
    cout << arr[idx] << endl;
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}

/*
Sample Input: 
5
3
1
0
7
5
Sample Output: 
5
7
0
1
3
*/