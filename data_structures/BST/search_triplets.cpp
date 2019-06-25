	///O(h) space for recursion log(n)
    ///O(n) time 
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
 
   ///the other way to modify head and tail in main is 
   ///reference to a pointer
   void fun(int *& ref_to_ptr){
       ///but don't use it
       ///stick to one
       ref_to_ptr = 0;/// set the passed pointer to zero
       ///otherwise if ref was not passed here
       ///then only  the copy of parameter is received is set to zero but not in main
       ///but the original pointer (outside the function ) remain unaffected
       ///you might have to use double pointer here like below
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
 
    bool search_triplets(int sum,node* head ,node* tail){
        /// don't try to use double pointer without any reason otherwise it might modify your result in main
        node* limit = tail->left;
        for(node* temp = head;temp!=limit;temp=temp->right){
            node* low = temp->right;
            node* high = tail;
            int k = sum - temp->key;
            //exit(0);
            while(low!=high){
                if(low->key + high->key == k){
                    return true;
                }
                else if(low->key + high->key > k)
                    high=high->left;
                else
                    low=low->right;
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
 
        node *head=NULL,*tail=NULL;
        convertBstToDll(root,&head,&tail);
 
 
        cout<<search_triplets(60,head,tail);
	}
