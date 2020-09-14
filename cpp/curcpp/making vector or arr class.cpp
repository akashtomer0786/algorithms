#include<bits/stdc++.h>
using namespace std;
class employee{
public:
    string name;
    employee(string n){
        this->name = n;
    }
};
class manager : public employee{
public:
    int id;
    manager(string name,int id):employee(name){
        this->id = id;
    }
};
class system1{
public:
    ///vector or array whatever you are using don't make it 
    /// using pointer 
    vector<manager>managerList;
    bool addmanager(manager m){
        for(auto &x : managerList){
            if(x.id==m.id)return false;
        }
        managerList.push_back(m);
        return true;
    }
    void print(){
        for(auto &p : managerList){
            cout<<p.name<<endl;
        }
    }
};
int main(){
    system1 s;
    manager m("Akash",8);
    s.addmanager(m);
    s.print();

}
