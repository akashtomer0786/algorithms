#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int *arr;
    int top;
    int capacity;
};
Stack* createstack(int cap){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (int*)malloc(sizeof(Stack)*cap);
    s->top = -1;
    s->capacity = cap;
}
void push(Stack* s,int ele){
    if(s->top+1==s->capacity){
        cout<<"full";
    }
    s->arr[++s->top]=ele;
}
int pop(Stack* s){
    if(s->top==-1){
        cout<<"tempt_y";
    }
    int temp = s->arr[s->top--];
    return temp;
}
///or you can make isfull() or isempty()
int main(){

}
