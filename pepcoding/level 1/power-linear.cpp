// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/introduction-to-recursion/power-linear-official/ojquestion

#include<iostream>
using namespace std;

int power(int x,int n){
   // write your code here
    if (n == 0) return 1;
    return x * power(x, n - 1);
}


int main(){
    int n,x; cin>>x>>n;
    cout<<power(x,n);
}

/*
Sample Input: 
2
5
Sample Output: 
32
*/