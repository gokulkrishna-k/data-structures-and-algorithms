#include<iostream>
#include<conio.h>
using namespace std;

void displayArray(int a[]) {
    int i;
    for (i = 0; i < =sizeof(a); i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}


int main() {
    
    int i ,j ,a[] = { 5,23,1,34,22,6,3,43,2};
    int gap, n = (sizeof(a)/sizeof(a[0])), temp;

    displayArray(a);
    
    for(gap = n/2; gap >=1 ; gap=gap/2) {
        for(j = gap; j<n; j++ ) {
            for(i = j-gap; i>=0; i=i-gap) {
                
                if(a[i+gap]>a[i]) {
                    break;
                }
                else {
                    temp =a[i];
                    a[i] = a[i+gap];
                    a[i+gap] = temp;
                }
            }
        }
    }
    displayArray(a);
    return 0;
}
