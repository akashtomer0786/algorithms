#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int minidx = i;
        for(int j=i+1;j<n;j++){
            if(a[minidx]>a[j]){
                minidx=j;
            }
        }
        swap(a[minidx],a[i]);
    }
}
int main(){
    int a[]={4,1,2,-1,1,0};
    selection_sort(a,6);
    for(int i = 0;i<6;i++){
        cout<<a[i]<<" ";
    }
}
