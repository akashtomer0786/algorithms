	#include<stdio.h>
	#include<stdlib.h>
	#include<iostream>
	#include<vector>
	#include<stack>
	using namespace std;
 
	struct node {
		int key;
		struct node *left;
		struct node *right;
	};
	node* newnode(int data) {
		node* n = (node*)malloc(sizeof(node));
		n->key = data;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	node* insert_key(node* root,int key){
	    if(root==NULL){
            return root=newnode(key);
	    }
	    if(key<root->key)
            root->left=insert_key(root->left,key);
        else if(key>root->key)
            root->right=insert_key(root->right,key);
 
        return root;
 
	}
	bool search_key(node* root,int key){
	    if(root->key==key)
            return true;
        if(root->key>key)
            return search_key(root->left,key);
        else if(root->key<key)
            return search_key(root->right,key);
        return false;
	}
	void inorder(struct node* root){
	    if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
	}
 
 
    void convertBstToDll(node* root,node** head,node** tail){
        if(root==NULL)
            return;
        convertBstToDll(root->left,head,tail);
        root->left=*tail;
        if(*tail!=NULL)
            (*tail)->right=root;
        if(*head==NULL)
            *head=root;
        *tail=root;
 
        convertBstToDll(root->right,head,tail);
    }
 
	int main() {
		struct node *root = NULL;
		root=insert_key(root, 15);
 
		root=insert_key(root, 25);
		root=insert_key(root, 20);
		root=insert_key(root, 22);
		root=insert_key(root, 30);
		root=insert_key(root, 18);
		root=insert_key(root, 10);
		root=insert_key(root, 8);
		root=insert_key(root, 9);
		root=insert_key(root, 12);
		root=insert_key(root, 6);
 
        node *head=NULL,*tail=NULL;
        convertBstToDll(root,&head,&tail);
 
        while(head){
            cout<<head->key<<"  ";
            head=head->right;
        }
	}
