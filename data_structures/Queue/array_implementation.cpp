    #include<iostream>
    #include<limits.h>
    using namespace std;
    #define MAX_SIZE 10
    class Queue{
    public:
        //int MAX_SIZE;
        int a[MAX_SIZE];
        int front1;
        int rear;
        Queue(){
            front1=-1;
            rear=-1;
        }
 
        bool isempty(){
            return front1==-1 && rear==-1;
        }
        bool isfull(){
            return ((rear+1)%MAX_SIZE)==front1;
        }
        void Enqueue(int x){
            if(isempty()){
                front1=rear=0;
            }
            else if(isfull()){
                return ;
            }
            else{
                rear=(rear+1)%MAX_SIZE;
            }
            a[rear]=x;
        }
        void Deque(){
            if(isempty())return;
            else if(front1==rear)front1=rear=-1;
            else front1=(front1+1)%MAX_SIZE;
        }
        int fron(){
            if(front1==-1){
                return INT_MIN;
            }
            return a[front1];
        }
        void print1(){
            if(isempty())return;
            int i=front1;
            while(1){
                cout<<a[i]<<endl;
                i=(i+1)%MAX_SIZE;
                if(i==rear+1)break;
            }
        }
 
    };
    int main(){
        Queue *Q = new Queue;
        Q->Enqueue(2);
        Q->Enqueue(4);
        Q->Enqueue(6);
        Q->Enqueue(8);
        //Q->print1();
        Q->Deque();
        Q->print1();
 
 
    }
 
