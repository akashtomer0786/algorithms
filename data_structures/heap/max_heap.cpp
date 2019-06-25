#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i){
    ///root is supposed to be largest
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
 
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
 
}
///this is inplace not using any extra space
void heapsort(int a[],int n){
    ///start heapify largest non leaf element
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    ///uncomment here to apply heap sort
    //for(int i=n-1;i>=0;i--){
      //  swap(a[0],a[i]);
        //heapify(a,i,0);
    //}
}
int extract_max(int a[],int &n){
    if(n<=0)
        return INT_MIN;
    if(n==1){
        n--;
        return a[0];
    }
    int mx = a[0];
    a[0] = a[n-1];
    n--;
    heapify(a,n,0);
    return mx;
 
}
 
void increase_key(int a[],int i,int key){
    a[i]=key;
    while(i!=0 && a[(i-1)/2] < a[i]){
        swap(a[i],a[(i-1)/2]);
        i = (i-1)/2;
    }
}
///decrease_key will not affect on above subtree
///so to fix its below part call heapify()
void decrease_key(int a[],int i,int key,int n){
    a[i]=key;
    heapify(a,n,i);
}
int main(){
    int a[]={12,11,13,5,6,7};
    heapsort(a,6);
    //increase_key(a,1,9);
    decrease_key(a,1,8,6);
    for(int i=0;i<6;i++){
        cout<<a[i]<<endl;
    }
}
