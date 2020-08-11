#include<bits/stdc++.h>
using namespace std;
///  friend function
class vehicle{
    int vehiclenumber; ///this member cannot be setted using constructors because it is private
public:
    int fuelcapacity;
    int maxspeed;
    friend void printall(vehicle v);  ///just declare the prototype of function with friend keyword

    vehicle(int f,int m){
        fuelcapacity=f;
        maxspeed=m;
    }
    void set_veh_no(int val){
        vehiclenumber=val;
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
void printall(vehicle v){
    cout<<v.vehiclenumber<<endl;
}
int main(){
    class vehicle v(100,200);
    v.print_vehicle();
    ///v.printall(); /// you cannot call printall functions like this
    ///because friend function is not for this kind of functionality
    ///If you create object of vehicle inside friend function it can access all the private and protected member of vehicle
    v.set_veh_no(1001);
    printall(v); ///printall() will be called independently
    class bike b();
}
