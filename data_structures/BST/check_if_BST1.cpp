bool solve(Node* root,Node* &prev){
    if(root==NULL)
        return true;
    bool left = solve(root->left,prev);
    if(root->data <= prev->data)
        return false;
    prev = root;
    return left && solve(root->right,prev);
}
bool isBST(Node* root) {
    Node* prev = new Node(INT_MIN);
    if(solve(root,prev))
    return 1;
    else 
    return 0;
}
