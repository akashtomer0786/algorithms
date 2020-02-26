#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int n){
    int hole;
    int temp;
    for(int i=1;i<n;i++){
        hole=i;
        while(hole>0 && a[hole-1]>a[hole]){
            swap(a[hole-1],a[hole]);
            hole--;
        }
    }
}

int main(){
    int a[]={4,1,2,-1,1,0};
    solve(a,6);
    for(int i = 0;i<6;i++){
        cout<<a[i]<<" ";
    }
}
