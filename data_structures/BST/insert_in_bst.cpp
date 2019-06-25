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
	void insert_key(node** root, int key) {
		if (*root == NULL) {
			node* n = newnode(key);
			*root = n;
			return;
		}
 
		if (key <= (*root)->key)
			insert_key(&((*root)->left), key);
		else
			insert_key(&((*root)->right), key);
 
	}
	void inorder(struct node* root){
	    if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
	}
	int main() {
		struct node *root = NULL;
		insert_key(&root, 50);
 
		insert_key(&root, 30);
		insert_key(&root, 20);
		insert_key(&root, 40);
		insert_key(&root, 70);
		insert_key(&root, 60);
		insert_key(&root, 80);
		inorder(root);
 
	}
