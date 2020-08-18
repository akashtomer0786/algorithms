#include<iostream>
using namespace std;
struct stack{
    int tp;
    int capacity;
    int *a;
    stack(int capacity){
        this->capacity=capacity;
        tp=-1;
        a = new int[capacity];
    }
};
void push(stack* st,int val){
    if(st->tp==-1){
        st->tp=0;
        st->a[st->tp]=val;
    }
    if(st->tp==st->capacity-1)return;

    st->tp++;
    st->a[st->tp]=val;
}
bool isempty(stack* st){
    return st->tp==-1;
}
void pop(stack* st){
    if(isempty(st))return;
    st->tp--;
}
int top(stack* st){
    if(isempty(st))return INT_MAX;
    return st->a[st->tp];
}
int main(){
    stack *st = new stack(10);

}
