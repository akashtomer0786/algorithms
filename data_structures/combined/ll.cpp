#include<bits/stdc++.h>
using namespace std;
struct node{
    node* next;
    int data;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
int sz=0;
node* insert_at_head(node* head,int val){
    sz++;
    node* temp = new node(val);
    temp->next = head;
    return temp;
}
node* insert_at_tail(node* head,int val){
    sz++;
    if(!head){
        head = new node(val);
    }
    node* temp = new node(val);
    while(head->next){
        head=head->next;
    }
    head->next = temp;
}
node* insert_at_n(node* head,int val,int n){
    ///can i assume that nth posiion is valid
    if(n>sz+1)return head;
    sz++;
    node* org = head;
    if(!head)return new node(val);
    if(n==1){
        org = new node(val);
        org->next = head;
        return org;
    }
    int pos=1;

    node* prev = NULL;
    while(pos<n){
        prev = head;
        head=head->next;
        pos++;
    }
    prev->next = new node(val);
    prev->next->next = head;
    return org;
}
node* delete_at_nthpos(node* head,int n){
    if(n>sz)return head; ///invalid
    if(n==1){
        node* temp = head;
        head=head->next;
        if(!head)return NULL;
        free(temp);
        return head;
    }
    int pos=1;
    node* org = head;
    node* prev = NULL;
    while(pos<n){
        prev = head;
        head=head->next;
        pos++;
    }
    if(!head)return org;
    prev->next = head->next;
    free(head);
    return org;
}
void print_list(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    node* head = NULL;
    head=insert_at_n(head,2,1);
    head=insert_at_n(head,3,1);

    head=delete_at_nthpos(head,1);
    print_list(head);
}
