#include<stdexcept>
#include<iostream>
using namespace std;
class Complex{
public:
    int real;
    int img;
    Complex(){
        real=img=0;
    }
    Complex(int a,int b){
        real = a;
        img = b;
    }

    ///inside this operator overloading is not valid
    ///we need to overload with one passing argument and and use this->real + a.real and this->img + b.img
    ///outside class this is valid
    Complex operator + (Complex a,Complex b){
        Complex res;
        res.real=a.real+b.real;
        res.img=a.img+b.img;
        return res;
    }
};

int main(){
    Complex obj1(2,3);
    Complex obj2(2,3);

    Complex res = obj1 + obj2;

    cout<<res.img<<" "<<res.real<<endl;
}
