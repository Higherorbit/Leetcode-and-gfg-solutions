class Solution {
public:
    vector<string>ans;
    void traverse(TreeNode* root,string t){
        if(root->left==NULL and root->right==NULL){
            ans.push_back(t);
            return ;
        }
        if(root->left)
            traverse(root->left,t+"->"+ to_string(root->left->val));
        if(root->right)
            traverse(root->right,t+"->"+ to_string(root->right->val));
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        traverse(root,to_string(root->val));
        return ans;
    }
};