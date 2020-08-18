#include<iostream>
using namespace std;
struct node{
    node* next;
    int data;
    node(int d){
        data=d;
        next=NULL;
    }
};
struct queue{
    node* front;
    node* rear;
    int capacity;
    queue(int c){
        capacity=c;
        front=NULL;
        rear=NULL;
    }
};
void push(queue* q,int val){
    if(q->front==NULL && q->rear==NULL){
        q->front = new node(val);
        q->rear = q->front;
        q->capacity--;
        return;
    }
    if(q->capacity==0)return;
    q->rear->next = new node(val);
    q->rear = q->rear->next;
    q->capacity--;
}
void pop(queue* q){
    //cout<<q->capacity<<endl;
    if(q->capacity==4)return;
    q->capacity++;
    if(q->front==q->rear){
        free(q->front);
        q->front=NULL;
        q->rear=NULL;
        return;
    }
    node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}
void print(queue* q){
    node* temp = q->front;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    struct queue* q = new queue(4);
    push(q,2);
    push(q,3);
    print(q);
    pop(q);
    print(q);
    pop(q);
    pop(q);
}
