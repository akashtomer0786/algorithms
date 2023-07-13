/**
In Strategy pattern, a class behavior or its algorithm can be changed at run time. This type of design pattern comes under behavior pattern.
In Strategy pattern, we create objects which represent various strategies and a context object whose behavior varies as per its strategy object.
The strategy object changes the executing algorithm of the context object.
**/
#include<bits/stdc++.h>
using namespace std;
class SortVectorStrategy{
public:
    virtual void Sort(vector<int> &a) = 0;
};
class BubbleSort: public SortVectorStrategy{
public:
    void Sort(vector<int>&a){
        ///bubble Sort logic
    }
};
class InsertionSort: public SortVectorStrategy{
public:
    void Sort(vector<int>&a){
        ///insertion Sort logic
    }
};

class Context{
private:
    SortVectorStrategy* sorter;
public:
    Context(SortVectorStrategy* S){
        this->sorter = S;
    }
    doSort(vector<int>& a){
        sorter->Sort(a);
    }
};
int main(){
    vector<int>a;
    Context* myContext = new Context(new InsertionSort());
    myContext->doSort(a);
}
