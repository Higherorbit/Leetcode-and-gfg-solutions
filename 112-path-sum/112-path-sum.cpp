class Solution {
public:
    vector<int>v;
    void traverse(TreeNode* root,int t){
        if(root->left== NULL and root->right==NULL){
            v.push_back(t);
        }
        if(root->left)
        traverse(root->left,t+root->left->val);  
        if(root->right)
        traverse(root->right,t+root->right->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        traverse(root,root->val);
        for(auto x:v){
            if(x==targetSum){
                return true;
            }
        }
        return false;
    }
};