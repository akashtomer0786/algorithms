#include<bits/stdc++.h>
using namespace std;

/// runtime polymorphism
class vehicle{
public:
    int fuelcapacity;
    int maxspeed;

    vehicle(int f,int m){
        fuelcapacity=f;
        maxspeed=m;
    }

    virtual void print_vehicle(){
        cout<<"This is Vehicle"<<endl;
    }
};
class car:public vehicle{
public:
    bool foursitter;
    string fueltype;
    friend void printall();
    car(bool f,string fuelt,int f1,int m):vehicle(f1,m){
        foursitter=f;
        fueltype=fuelt;
    }
    void print_vehicle(){
        cout<<"This is car"<<endl;
    }
};
class bike:public vehicle{
    string braketype; /// abs or normal

    void print_vehcile(){
        cout<<"This is bike"<<endl;
    }
};
void printall(){
    cout<<"This will print all"<<endl;
}
int main(){
    class vehicle v(100,200);
    v.print_vehicle();
   /// v.printall();
    class bike b();

    vehicle *base = new car(false,"CNG",100,100);

    ///valid calls
    base->fuelcapacity;
    base->maxspeed;
    base->print_vehicle();

    ///we cannot call the braketype since it is not in the base class
    base->braketype;





}
