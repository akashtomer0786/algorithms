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
