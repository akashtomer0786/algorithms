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
 
    void solve_triplet(node* root,vector<int> &v){
        if(root==NULL)
            return;
        solve_triplet(root->left,v);
        v.push_back(root->key);
        solve_triplet(root->right,v);
 
    }
   bool bst_triplet(node* root,int sum,vector<int> &ans){
        vector <int> v;
        solve_triplet(root,v);
        for(int i=0;i<=v.size()-3;i++){
            int low = i+1;
            int high = v.size()-1;
            int k = sum - v[i];
            while(low<high){
                if(v[low]+v[high]==k){
 
                    ans={v[low],v[high],v[i]};
                    return true;
 
                }
 
                else if(v[low]+v[high]>k)
                    high--;
                else
                    low++;
            }
 
 
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
	    vector<int> ans;
	    if(bst_triplet(root,40,ans))
	    for(auto v : ans)
            cout<<v<<endl;
	}
