#include<iostream>
using namespace std;

int main(){
    try{
        try{
            throw "a character exception";
        }catch(const char* e){
            cout<<"character type in inner block -->"<<e<<endl;
            cout<<"rethrowing the exception"<<endl;
            ///the catched exception can be re thrown again
            throw;
        }
    }catch(const char *e){
        cout<<"character type in outer block "<<e<<endl;
    }catch(...){
        cout<<"unexpected exception in outer block "<<endl;
    }
}
