#include<iostream>
using namespace std;

void displayArray(int a[]) {
	for(int i=0; i<=sizeof(a);i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void swap(int *a,int *b) {
	int t = *a;
	*a =*b;
	*b = t;
}

int partionArray(int a[],int low,int high) {
	int pivot = a[high], temp;
	int i = low-1;
	int j;
	for (j=low ; j<high;j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i],&a[j]);
		}	
	}
	swap(&a[i+1],&a[high]);
	return i+1;
	
}

void quickSort(int a[],int low,int high){
	if(low<high){
		int pivot = partionArray(a,low,high);
			quickSort(a,low,pivot-1);
			quickSort(a,pivot+1,high);
	}
}

int main(){
	int a[] = {7,34,2,8,1,32,11,56,3};
	int n =sizeof(a)/sizeof(a[0]);
	cout<<"Unsorted array:";
	displayArray(a);
	quickSort(a,0,n-1);
	cout<<"Sorted array  :";
	displayArray(a);
	return 0;
}
