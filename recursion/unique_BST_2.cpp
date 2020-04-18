/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int s ,int e){
    vector<TreeNode*>vect;
    if(s>e){
        vect.push_back(NULL);
        return vect;
    }
    if(s==e){
        vect.push_back(new TreeNode(s));
        return vect;
    }
    
    for(int i=s;i<=e;i++){
        auto left =  solve(s,i-1);
        auto right = solve(i+1,e);
        
        for(auto l : left){
            for(auto r : right){
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                vect.push_back(root);
            }
        }
    }
    return vect;
}
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
        return solve(1,n);
    }
};
