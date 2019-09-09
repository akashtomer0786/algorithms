#include<iostream>
#include<vector>
using namespace std;
void merge(int a[],int left[],int right[],int l,int r){
    int i=0,j=0,k=0;
    while(i<l && j<r){
        if(left[i]>right[j]){
            a[k++]=right[j++];
        }
        else a[k++]=left[i++];

    }
    while(i<l){
        a[k++]=left[i++];
    }
    while(j<r){
        a[k++]=right[j++];
    }
}

void mergesort(int a[],int n){
    if(n<2)return;
    int mid = (n)>>1;
    int *left = new int[n/2];
    int *right = new int[n-n/2];
    for(int i=0;i<mid;i++){
        left[i]=a[i];
    }
    for(int i=mid;i<n;i++){
        right[i-mid]=a[i];
    }
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(a,left,right,mid,n-mid);
    delete[] left;
    delete[] right;
}

int main(){
    int a[]={1,2,3,4,-5,1};
    mergesort(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";
}
