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
    int ans;
    int sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=max(0,sum(root->left));
        int right=max(0,sum(root->right));
        ans=max(ans,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        ans=INT_MIN;
        sum(root);
        return ans;
    }
};