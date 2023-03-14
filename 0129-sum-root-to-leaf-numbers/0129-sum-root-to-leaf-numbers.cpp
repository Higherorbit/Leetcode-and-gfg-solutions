/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> v;
    void solve(TreeNode* root, string t){
        if(root->left==NULL and root->right==NULL){
            v.push_back(t);
            return ;
        }
        if(root->left){
            solve(root->left,t+to_string(root->left->val));
        }
        if(root->right){
            solve(root->right,t+to_string(root->right->val));
        }
    }
    int sumNumbers(TreeNode* root) {
        solve(root,to_string(root->val));
        int ans=0;
        for(auto x:v){
            ans+=std::stoi(x);
        }
        return ans;
    }
};