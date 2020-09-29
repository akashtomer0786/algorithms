#include<bits/stdc++.h>
using namespace std;

// constructing 1
// constructing 2
// constructing 3
// constructing 4
// destructing object number 4
// destructing object number 3
// destructing object number 2
// destructing object number 1

class base{
public:
    static int cnt;
    int  id;
    base(){
        cnt++;
        id=cnt;
        cout<<"constructing "<<id<<endl;
    }
    ~base(){
        cout<<"destructing object number "<<id<<endl;
    }
};
int base::cnt=0;
int main(){
    base arr[4];
}
