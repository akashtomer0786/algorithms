#include<iostream>
using namespace std;
///when nothing is provided then argc==1  and argv[0] contains the file name
///when only one argument is provided then argv[1] contain that argument and argc==2
int main(int argc,char** argv){
    int num;
    int res=0;
    cout<<argc<<endl;
    if(argc==1){
        cout<<argv[0]<<endl;
    }
}
