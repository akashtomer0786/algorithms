#include<iostream>
#include<exception>

using namespace std;

int main(){
    try{
        throw runtime_error("runtime error");
    }catch(const char* err){
        cout<<err<<endl;
    }catch(int error){
        cout<<error<<endl;
    }catch(runtime_error e){
        cout<<e.what()<<endl;
    }catch(...){
        ///any unknown exception which doesn't matches any
        /// of the type mentioned then this catch block
        /// handle them too      
        cout<<"some exception occured"<<endl;
    }
    return 0;
}
