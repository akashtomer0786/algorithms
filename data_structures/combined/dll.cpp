#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        next = NULL;
        prev = NULL;
    }
};
int sz=0;
node* insert_at_nth(node* head,int val,int n){
    if(n>sz+1)return head; ///invalid case
    sz++;
    if(!head){
        return new node(val);
    }
    if(n==1){
        head->prev = new node(val);
        head->prev->next = head;
        return head->prev;
    }
    int pos=1;
    node* org=head,*pre;
    while(pos<n){
        pre=head;
        head=head->next;
        pos++;
    }
    pre->next = new node(val);
    pre->next->prev = pre;
    pre->next->next = head;
    if(head){
        head->prev = pre->next;
    }
    return org;
}
node* delete_at_nth(node* head,int n){
    if(n>sz)return head;///invalid case
    sz--;
    if(n==1){
        node* temp = head->next;
        if(!temp)return NULL;
        temp->prev=NULL;
        free(head);
        return temp;
    }

    int pos=1;
    node* pre;
    node* org=head;
    while(pos<n){
        pre=head;
        head=head->next;
        pos++;
    }
    pre->next = head->next;
    if(head->next)
    head->next->prev = pre;
    free(head);
    return org;
}
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    node* head = NULL;
    head=insert_at_nth(head,2,1);
    head=insert_at_nth(head,3,1);
    head=delete_at_nth(head,2);
    print(head);
}
