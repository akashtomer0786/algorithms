bool solve(Node* root,int minval,int maxval){
    if(root==NULL)
        return true;
    if(root->data >=maxval || root->data <=minval)
        return false;
    return solve(root->left,minval,root->data)&&solve(root->right,root->data,maxval);    
}
bool isBST(Node* root) {
    if(solve(root,INT_MIN,INT_MAX))
        return 1;
    else
        return 0;
}
