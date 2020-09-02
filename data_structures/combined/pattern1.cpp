#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x = n-2;

        for(int i=0;i<n;i++){
            cout<<"* ";
        }
        cout<<endl;
        for(int i=0;i<x-2;i++){
            cout<<"* ";
            for(int j=0;j<x;j++){
                cout<<"  ";
            }
            cout<<"* ";
            cout<<endl;
        }

        for(int i=0;i<n;i++){
            cout<<"* ";
        }

    }
}
