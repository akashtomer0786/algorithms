	#include<stdio.h>
	#include<stdlib.h>
	#include<iostream>
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
	void inorder(struct node* root){
	    if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
	}
	void postorder(node* root){
        if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<endl;
	}
	void preorder(node* root){
	    if(root==NULL)
            return;
        cout<<root->key<<endl;
        preorder(root->left);
        preorder(root->right);
 
	}
	node* find_min(node* root){
	    if(root->left==NULL){
            return root;
	    }
	    return find_min(root->left);
        }
	node* delete_key(node* root,int key){
        if(root->key<key)
            root->right=delete_key(root->right, key);
        else if(root->key>key)
            root->left=delete_key(root->left, key);
        else{
            if(root->left!=NULL && root->right == NULL){
                node* temp=root->left;
                free(root);
                return temp;
            }
            else if(root->right!=NULL && root->left ==NULL){
                node* temp=root->right;
                free(root);
                return temp;
            }
            else if(root->left==NULL && root->right ==NULL){
 
                free(root);
                return NULL;
            }
            else{
 
                node* temp = find_min(root->right);
 
                root->key=temp->key;
 
                root->right=delete_key(root->right,temp->key);
                //exit(0);
            }
        }
        return root;
	}
	int main() {
		struct node *root = NULL;
		root=insert_key(root, 50);
 
		root=insert_key(root, 30);
		root=insert_key(root, 20);
		root=insert_key(root, 40);
		root=insert_key(root, 70);
		root=insert_key(root, 60);
		root=insert_key(root, 80);
		root=delete_key(root,60);
		///root=delete_key(root,70);
		inorder(root);
		//postorder(root);
       // preorder(root);
	}
