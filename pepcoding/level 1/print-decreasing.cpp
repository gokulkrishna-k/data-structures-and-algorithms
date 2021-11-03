// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/print-decreasing-official/ojquestion

#include <iostream>
using namespace std;

void printDecreasing(int n){
    if(n == 0) return;
    cout << n << endl;
    printDecreasing(n - 1);
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}

/*
Sample Input: 
5
Sample Output: 
5
4
3
2
1
*/