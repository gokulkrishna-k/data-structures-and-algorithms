// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/print-increasing-decreasing-official/ojquestion

#include<iostream>
using namespace std;

void printIncDec(int n){
    // write your code here
    if(n == 0) return;
    cout << n <<endl;
    printIncDec(n - 1);
    cout<< n << endl;
    
}


int main(){
    int n; cin>>n;
    printIncDec(n);
}

/*
Sample Input: 
3
Sample Output: 
3
2
1
1
2
3
*/