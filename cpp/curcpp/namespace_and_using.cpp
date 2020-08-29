#include <iostream>
#include <vector>
///standard library functions in cpp are defined in std namespace

///definition for namespace 

A namespace is a declarative region that provides a scope to the identifiers 
(the names of types, functions, variables, etc) inside it. 
Namespaces are used to organize 
code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries.


The using keyword is used to: Bring a specific member from the namespace into the current scope. Bring all members from 
the namespace into​ the current scope. Bring a base class method ​or variable into the current class's scope.

namespace utilz{
    void print_array(const int data[],int size){
        for(int i=0;i<size;i++){
            std::cout<<data[i]<<std::endl;
        }
        std::cout<<std::endl;
    }
}
///if we don't want to use utilz before print_array(data,3)
///then we can use
using namespace utilz;

int main(){
    int data[] = {1,2,3};
    utilz::print_array(data,3);
    std::cout<<data[0]<<std::endl;
}
