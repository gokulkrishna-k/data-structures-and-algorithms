#include<iostream>
using namespace std;

void displayArray(int a[],int n) {
	for(int i= 0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void insertionSort(int a[], int n) {
	int i;
	for(i=1; i<n; i++) {
		int key = a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main() {
	int a[] = {3,45,2,4,34,9,54,0};
	int n = sizeof(a)/sizeof(a[0]);
	displayArray(a,n);
	insertionSort(a,n);
	displayArray(a,n);
}
