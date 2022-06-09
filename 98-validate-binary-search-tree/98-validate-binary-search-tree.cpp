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
    vector<int> v;
    void traverse(TreeNode* root){
        if(root==NULL){
            return ;
        }
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        traverse(root);
        set<int>s;
        for(auto x:v){
            s.insert(x);
        }
        if(s.size()!=v.size())
        return false;
        return is_sorted(v.begin(),v.end());
    }
    
};