/*
We are given a ribbon of length ‘n’ and a set of possible ribbon lengths. Now we need to cut the
ribbon into the maximum number of pieces that comply with the above-mentioned possible lengths. Write a
method that will return the count of pieces.
Example 1:
    n: 5
    Ribbon Lengths: {2,3,5}
    Output: 2
    Explanation: Ribbon pieces will be {2,3}.
Example 2:
    n: 7
    Ribbon Lengths: {2,3}
    Output: 3
    Explanation: Ribbon pieces will be {2,2,3}.
Example 3:
    n: 13
    Ribbon Lengths: {3,5,7}
    Output: 3
    Explanation: Ribbon pieces will be {3,3,7}.
*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>a,int amount,int index){
    if(index==0)return INT_MIN;
    if(amount==0)return 0;
    if(amount<0)return INT_MIN;

    return max(1+solve(a,amount-a[index-1],index),solve(a,amount,index-1));

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int &i : a)cin>>i;
        int amount;
        cin>>amount;
        cout<<solve(a,amount,n)<<endl;
    }
}
