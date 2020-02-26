#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i;j++){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
            }
        }
    }
}
int main(){
    int a[]={4,1,2,-1,1,0};
    bubble_sort(a,6);
    for(int i = 0;i<6;i++){
        cout<<a[i]<<" ";
    }
}
