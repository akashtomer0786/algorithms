#include<bits/stdc++.h>
using namespace std;
//https://www.mylearningmania.com/2021/02/deep-and-shallow-copy-in-cpp.html
class Point{
private:
    int x,y;
    int *p;
public:
    Point(int x1,int y1){
        x=x1;
        y=y1;
        p=NULL;
    }
    Point(Point &p2){
        x=p2.x;
        y=p2.y;
        p=new int;
        *p = *p2.p; ///thats why we really need copy constructor to make deep copy
        // since p is a address we are not placing it directly in current class object instead we will place the value at that pointer.

    }
    ///since x and y are private we need getx and gety to take them as input
    /// with the help of constructor it is not possible
    void setx();
    void sety();
    
    int getx();
    int gety();
};
int main(){

}
