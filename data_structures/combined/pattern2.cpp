#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int space=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<space;j++){
                cout<<" ";
            }
            for(int j=0;j<2*i+1;j++){
                cout<<"*";
            }
            cout<<endl;
            space--;
        }
    }
}
