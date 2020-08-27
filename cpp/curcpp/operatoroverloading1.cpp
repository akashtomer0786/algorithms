#include<bits/stdc++.h>
using namespace std;
struct complex_num{
    int img;
    int real;
    complex_num(){
    }
    complex_num(int img,int real){
        this->img=img;
        this->real=real;
    }
};
complex_num operator+(complex_num &a,complex_num &b){
    complex_num res;
    res.img = a.img+b.img;
    res.real = a.real+b.real;
}

int main(){
    complex_num obj1(2,2);
    complex_num obj2(3,3);
    obj1 = obj2+obj1;
    cout<<obj1.img<<" "<<obj1.img;

}
