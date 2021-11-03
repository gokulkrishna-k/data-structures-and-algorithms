// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/print-increasing-official/ojquestion

#include<iostream>
using namespace std;

void printIncreasing(int n){
    if (n == 0) return;
    printIncreasing(n - 1);
    cout << n << endl;
}


int main(){
    int n; cin>>n;
    printIncreasing(n);
}

/*
Sample Input: 
5
Sample Output: 
1
2
3
4
5
*/