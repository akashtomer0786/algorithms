#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int start,int end){
    int pivot=a[end];
    int pindex=start;
    for(int i=start;i<=end;i++){
        if(a[i]<pivot)swap(a[i],a[pindex++]);
    }
    swap(a[pindex],a[end]);
    return pindex;
}
void quick_sort(int a[],int start,int end){
    if(start>=end)return;
    int partit = partition(a,start,end);
    quick_sort(a,start,partit-1);
    quick_sort(a,partit+1,end);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        quick_sort(a,0,n-1);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
