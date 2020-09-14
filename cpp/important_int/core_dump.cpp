#include<iostream>
#include<stdio.h>
using namespace std;

/// first compile it like g++ -g app.cpp
///it will create core file
/// gdb a.out core
///it will give you the line number where segmentation fault occured
///we are talking about here linux
//A “core dump” is a snapshot of memory at the instant the program crashed, typically saved in a file called “core”
int main(){
    int *i = NULL;
    *i = 10;
    cout<<*i<<endl;
}
