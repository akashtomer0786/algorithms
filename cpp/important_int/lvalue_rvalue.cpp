#include<iostream>
#include<stdio.h>
using namespace std;

///lvalue - An object that occupies some identified location in memory
///rvalue - Any object that is not a value
int main(){
    int i; ///i is lvalue
    i=2; ///memory content is modified
    
    class dog;
    dog d1; ///lvalue of user defined type (class)
    ///most variable in c++ code are lvalues
    
    int x=2  ///2 is an rvalue
    int x = i+2; /// i+2 is an rvalue
    int *p = &(i+2) ///Error
    i+2 = 4; ///Error
    2 = i; ///Error
    
    dog d1;
    d1 = dog(); ///dog() is rvalue of user defined type (class)
    
    int sum(int x,int y){
        int i = sum(3,4);  ///sum(3,4) is rvalue
    }
    
    
    
    /// Reference (or lvalue reference):
    int i;
    int &r = i;
    int &r = 5;   ///Error
}
