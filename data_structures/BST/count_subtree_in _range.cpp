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
    bool count_bst(node* root,int low ,int high,int &cnt){
        if(root==NULL)
            return true;
        bool l = count_bst(root->left,low,high,cnt);
        bool r = count_bst(root->right,low,high,cnt);
        if(l && r && root->key >=low && root->key <=high){
            cnt++;
            return true;
        }
        return false;
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
		//root=delete_key(root,60);
		//iterative(root);
		int cnt = 0;
		count_bst(root,5,20,cnt);
		cout<<cnt<<endl;
		//cout<<solvelca(root,30,20)->key;
		///root=delete_key(root,70);
		//inorder(root);
		//postorder(root);
       // preorder(root);
	}
