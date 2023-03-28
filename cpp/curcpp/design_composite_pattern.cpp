#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Department{
public:
    virtual void printDepartmentName() = 0;
};

class FinancialDepartment: public Department { /// first leaf component
private:
    int id;
    string name;
public:
    void printDepartmentName(){
        cout<<"Welcome to Financial Department"<<endl;
    }
};
class SalesDepartment: public Department { /// second leaf component
private:
    int id;
    string name;
public:
    void printDepartmentName(){
        cout<<"Welcome to Sales Department"<<endl;
    }
};

class HeadDepartment: public Department {
private:
    int id;
    string name;
    vector<Department*> departments;
public:
    void printDepartmentName(){
        for(auto d: departments){
            d->printDepartmentName();
        }
    }

    void addDepartment(Department* d){
        departments.push_back(d);
    }

    void removeDepartment(Department* d){

    }
};

int main(){
    Department* d1 = new FinancialDepartment();
    Department* d2 = new SalesDepartment();

    HeadDepartment* headDepartment = new HeadDepartment();

    headDepartment->addDepartment(d1);
    headDepartment->addDepartment(d2);
    headDepartment->printDepartmentName();
}
