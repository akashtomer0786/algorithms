#include<bits/stdc++.h>
using namespace std;
class Account{
private:
    int balance;
    static float roi;  ///only declared here
public:
    void set_balance(int b=10){
        balance = b;
    }
    static void setRoi(float r){
        roi=r;
    }
};
/// we need to define static variable outside the class to
///using scope resolution operator
float Account:: roi = 3.5;
int main(){
    Account a1,a2;
    ///memory will be allocated for roi once it doesn't matter
    ///whether 0 or many object of Account is created

    ///now we know that if there is no object of class Account
    ///still variable ROI exist  then we must be able to
    ///access it without the object is being created
    ///for that purpose we can make static
    /// function to which we can call without the creation
    /// of object
    Account::setRoi(4.5f);
    
    ///iski need hoti hi isiliye hai ki jab class ka koi object nahi 
    ///hai toh un variable ko(static) tab bhi exist karte hai kaise 
    ///access karei for other purpose we don't need to use these
}
