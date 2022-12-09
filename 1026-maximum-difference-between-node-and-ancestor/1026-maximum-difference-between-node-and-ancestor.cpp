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
    int ans=INT_MIN;
    void traverse(TreeNode* root, int first,int last){
        if(root==NULL){
            return ;
        }
        int bhalue=root->val;
        ans=max(ans,max(abs(bhalue-first),abs(bhalue-last)));
        first=max(first,root->val);
        last=min(last,bhalue);
        traverse(root->left,first,last);
        traverse(root->right,first,last);
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=INT_MIN;
        int curMax=root->val,curMin=root->val;
        traverse(root,curMax,curMin);
        return ans;
    }
};