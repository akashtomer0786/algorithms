/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/
     Node*  solve(Node* root,int n1,int n2){
         if(root==NULL)return NULL;
         if(root->data==n1 || root->data==n2) return root;
         Node* left = solve(root->left,n1,n2);
         Node* right = solve(root->right,n1,n2);
         if(left!=NULL && right!=NULL) return root;
         if(left!=NULL)return left;
         if(right!=NULL)return right;
         return NULL;
         
     }
Node * lca(Node* root ,int n1 ,int n2 )
{
    return solve(root,n1,n2);
}
