#include<bits/stdc++.h>
using namespace std;
int tree[100];
int A[100]={1,2,3,4,5};
void build(int node,int start,int end1){
    if(start==end1){
        tree[node]=A[start];
        return;
    }
    int mid = (start + end1)/2;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end1);
    tree[node] = (tree[2*node+1]+tree[2*node+2]);
}
void update(int node,int start,int end1,int idx,int val){
    if(start==end1){
        A[idx] += val;
        tree[node] += val;
    }
    int mid = (start+end1)/2;
    if(idx>=start && idx <=mid)
        update(2*node+1,start,mid,idx,val);
    else
        update(2*node+2,mid+1,end1,idx,val);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}
int query(int node,int start,int end1,int l,int r){
    if(r<start or l>end1){
        return 0;
    }
    if(l<=start and end1<=r){
        return tree[node];
    }
    int mid = (start + end1)/2;
    int p1 = query(2*node+1,start,mid,l,r);
    int p2 = query(2*node+2,mid+1,end1,l,r);
    return (p1+p2);
}
int main(){
    build(0,0,4);
    update(0,0,4,1,0);
    cout<<query(0,0,4,0,1)<<endl;
    cout<<query(0,0,4,0,2)<<endl;
}
