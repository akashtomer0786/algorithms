#include<stdexcept>
#include<iostream>
using namespace std;

///if you didn't mention anything inside block then that will not be handled
void test() throw(int,char,runtime_error){ ///the type of exception it can throw
    throw runtime_error("what the hack");
    throw 20;
}
int main(){
    try{
        test();
    }catch(int e){
        cout<<"integer type "<<e<<endl;
    }catch(char c){
        cout<<"character type "<<c<<endl;
    }catch(runtime_error r){
        cout<<" runtime error type"<<r.what()<<endl;
    }
}
