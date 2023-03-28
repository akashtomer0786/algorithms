#include<bits/stdc++.h>
using namespace std;

enum VehicleType{
    VT_TWOWHEELER, VT_THREEWHEELER, VT_FOURWHEELER
};

class Vehicle{
public:
    virtual void printVehicle() = 0;
    static Vehicle* Create(VehicleType type);
    virtual ~Vehicle(){}
};

class TwoWheeler : public Vehicle{
public:
    void printVehicle(){
        cout<<"I am two wheeler "<<endl;
    }
};
class ThreeWheeler : public Vehicle{
public:
    void printVehicle(){
        cout<<"I am three wheeler "<<endl;
    }
};

/**
 Factory method to create objects of different types.
 Change is required only in this function to create a new object type
**/
Vehicle* Vehicle::Create(VehicleType type){
    if(type == VT_TWOWHEELER){
        return new TwoWheeler();
    } else if(type == VT_THREEWHEELER){
        return new ThreeWheeler();
    } else return NULL;
}
// Client class
class Client {
public:
    /**
    Client doesn't explicitly create objects
    but passes type to factory method "Create()"
    **/
    Client()
    {
        VehicleType type = VT_THREEWHEELER;
        pVehicle = Vehicle::Create(type);
    }
    ~Client() {
        if (pVehicle) {
            delete pVehicle;
            pVehicle = NULL;
        }
    }
    Vehicle* getVehicle()  {
        return pVehicle;
    }

private:
    Vehicle *pVehicle;
};

// Driver program
int main() {
    Client *pClient = new Client();
    Vehicle * pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
      delete pClient;
    return 0;
}
