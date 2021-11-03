// PROBLEM

//https://www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/factorial-official/ojquestion

#include<iostream>
using namespace std;

int factorial(int n){
    // write your code here
    if(n == 0) return 1;
    return n * factorial(n - 1);
    
}


int main(){
    int n; cin>>n;
    cout<<factorial(n);
}

/*
Sample Input: 
5
Sample Output: 
120
*/