#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int val=a[i];
        int hole=i;
        while(hole>0 && a[hole-1]>val){
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=val;
    }
}
int main(){
    int a[]={4,1,2,-1,1,0};
    solve(a,6);
    for(int i = 0;i<6;i++){
        cout<<a[i]<<" ";
    }
}
