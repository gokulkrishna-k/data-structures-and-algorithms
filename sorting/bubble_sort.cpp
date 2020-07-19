#include<iostream> 
using namespace std;


void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void displayArray(int a[],int n){
	for(int i=0; i< n;i++){
		cout<<a[i]<<" ";
		
	}
	cout<<"\n";
}
void bubbleSort(int a[], int n) {
	int i,j;
	for(i=0;i<n-1;i++) {
		for( j=0; j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}

int main() {
	int a[] = {34,2,45,13,3,245,4};
	int n = sizeof(a)/sizeof(a[0]);
	displayArray(a,n);
	bubbleSort(a,n);
	displayArray(a,n);
}
