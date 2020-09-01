#include<bits/stdc++.h>
using namespace std;
class a{
int x;
public:
    a(int y){
        x=y;
    }
    
    /// you can set them using constructor 
    ///but later in future if there is a requirement to
    ///change then you will not be able to do that
    
    ///for that set getter and setter for private member
};
int main(){
    a b(3);
    cout<<b.x;
}
