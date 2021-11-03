// PROBLEM

//https://pepcoding.com/resources/online-java-foundation/introduction-to-recursion/toh-official/ojquestion

#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id){
    if( n == 0) return;
    toh(n - 1, t1id, t3id, t2id );
    cout << n << "[" << t1id <<  " -> " << t2id << "]" << endl; 
    toh(n - 1, t3id, t2id, t1id );   
}

int  main() {

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
}

/*
Sample Input: 
3
10
11
12
Sample Output: 
1[10 -> 11]
2[10 -> 12]
1[11 -> 12]
3[10 -> 11]
1[12 -> 10]
2[12 -> 11]
1[10 -> 11]
*/