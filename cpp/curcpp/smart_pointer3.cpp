#include<iostream>
#include<memory>
#include<bits/stdc++.h>
using namespace std;
struct Son;
struct Mother;
struct Daughter;

struct Mother{
    ~Mother(){
        cout<<"Mother gone "<<endl;
    };
    void setSon(shared_ptr<Son>s){
        mySon=s;
    }
    void setDaughter(shared_ptr<Daughter>d){
        myDaughter=d;
    }
    ///try to make one by one them as shared and then see
    weak_ptr<Son>mySon;
    weak_ptr<Daughter>myDaughter;
};
struct Son{
    Son(shared_ptr<Mother>m):myMother(m){}
    ~Son(){
        cout<<"Son gone"<<endl;
    }
    shared_ptr<Mother>myMother;
};
struct Daughter{
    Daughter(shared_ptr<Mother>m):myMother(m){}
    ~Daughter(){
        cout<<"Daughter gone"<<endl;
    }
    shared_ptr<Mother>myMother;
};
int main(){
    shared_ptr<Mother>mother = shared_ptr<Mother>(new Mother);
    shared_ptr<Son>son = shared_ptr<Son>(new Son(mother));
    shared_ptr<Daughter>daughter = shared_ptr<Daughter>(new Daughter(mother));
    mother->setSon(son);
    mother->setDaughter(daughter);
}
