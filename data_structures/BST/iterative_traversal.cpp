	//space complexity for recursive O(height) and O(height) time
    //space compl for iterative is O(1) and O(height) time
    #include<stdio.h>
	#include<stdlib.h>
	#include<iostream>
	#include<vector>
	#include<stack>
	using namespace std;
    int iterative(node *root){
	    ///keep in mind that in iterative traversal you can,t traverse back without extra memory
	    ///we will use stack for this kind of work
	    stack<node*> st;
	    st.push(root);
 
	    while(!st.empty()){
        node *temp = st.top();
        st.pop();
        cout<<temp->key<<endl;
        if(temp->left!=NULL)
            st.push(temp->left);
        if(temp->right!=NULL)
            st.push(temp->right);
	    }
	}
	node* solvelca(node* root,int l,int r){
	    if(root==NULL || !search_key(root,l) || !search_key(root,r)){
            cout<<"NO LCA found";
            return 0;
        }
 
	    while(root){
 
            if(root->key>l && root->key >r)
                root=root->left;
            else if(root->key<l && root->key <r)
                root=root->right;
            else return root;
	    }
 
    }
    node* solvelca_rec(node* root,int l,int r){
 
        if(root->key>l && root->key>r){
            return solvelca_rec(root->left, l, r);
        }
        else if(root->key<l && root->key<r){
            return solvelca_rec(root->right, l, r);
        }
        return root;
    }
    int main(){
    }
 
