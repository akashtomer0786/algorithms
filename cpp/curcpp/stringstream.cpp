#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    cout<<s<<endl;

    stringstream ss(s);

    string token;

    while(getline(ss,token,' ')){
        cout<<token<<endl;
    }
}
