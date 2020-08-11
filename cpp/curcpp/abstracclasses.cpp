#include<bits/stdc++.h>
using namespace std;
class vehicle{
public:
    string description;

    virtual void setdes(string des)=0;
};

class car:public vehicle{
public:
    void setdes(string des){
        description=des;
    }
};
int main(){
    vehicle v;  ///object of abstract class cannot be created hence it will give error
    car c;
    c.setdes("description");
}
