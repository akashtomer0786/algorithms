#include<iostream>
#include<vector>
using namespace std;
struct queue{
    int capacity;
    int front;
    int rear;
    vector<int>a;
    queue(int capacity){
        this->capacity=capacity;
        this->front=-1;
        this->rear=-1;
        a.resize(capacity);
    }
};

void push(queue* q,int val){
    if(q->rear==(q->front+1)%q->capacity){
        return;
    }
    if(q->front==-1 && q->rear==-1){
        q->front=0;
        q->rear=0;
        q->a[0]=val;
        return;
    }

    q->rear=(q->rear+1)%q->capacity;
    q->a[q->rear]=val;
    return;
}
void pop(queue* q){
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
        return;
    }
    q->front=(q->front+1)%q->capacity;

}
bool isempty(queue* q){
    return q->rear==-1 && q->front==-1;
}
int top(queue* q){
    if(isempty(q)){
        return INT_MAX;
    }
    return q->a[q->front];
}

int main(){
    struct queue* q = new queue(100);
    push(q,2);
    push(q,3);
    cout<<top(q)<<endl;
    pop(q);
    cout<<top(q)<<endl;
    pop(q);
    cout<<top(q)<<endl;
    pop(q);
    cout<<top(q)<<endl;
    pop(q);

}
