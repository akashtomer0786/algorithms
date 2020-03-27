#include<bits/stdc++.h>
using namespace std;

void merge_arr(int a[],int l[],int r[],int nl,int nr){
    int i=0;
    int j=0;
    int k=0;
    while(i<nl && j<nr){
        if(l[i]<r[j]){
            a[k++]=l[i++];
        }else{
            a[k++]=r[j++];
        }
    }
    while(i<nl){
        a[k++]=l[i++];
    }
    while(j<nr){
        a[k++]=r[j++];
    }
}

void merge_sort(int a[],int n){

    if(n<2)return;

    int *l = new int[n/2];
    int *r = new int[n-n/2];
    for(int i=0;i<n/2;i++){
        l[i]=a[i];
    }
    int j=0;
    for(int i=n/2;i<n;i++){
        r[j++]=a[i];
    }
    merge_sort(l,n/2);
    merge_sort(r,n-n/2);
    merge_arr(a,l,r,n/2,n-n/2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];

        merge_sort(a,n);

        for(int i=0;i<n;i++)cout<<a[i]<<" ";

        cout<<endl;

    }
}
