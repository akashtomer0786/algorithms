#include<iostream>
#include<algorithm>
using namespace std;
int partition_qs(int a[], int start, int end1) {
	int pivot = end1 - 1;
	int pindex = start;
	for (int i = start; i < end1; i++) {
		if (a[i] < a[pivot]) {
			swap(a[i], a[pindex]);
			pindex++;
		}
	}
	swap(a[pindex], a[pivot]);
	return pindex;
}
void quicksort(int a[], int start, int end1) {
	//cout << sizeof(a);
	for (int i = 0; i < end1; i++) {
		//cout << a[i] << " ";
	}
	if (start < end1-1) {
		int pind = partition_qs(a, start, end1);
		quicksort(a, start, pind);
		quicksort(a, pind, end1);
	}
}
int main() {
	int a[] = { 3,-1,2,0 };
	quicksort(a, 0, 4);
	  for(int i=0;i<4;i++)
		 cout<<a[i]<<" ";
}
