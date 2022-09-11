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
int ans=0;
int traverse(TreeNode* r){
    if(r==NULL){
        return 0;
    }
    int l=traverse(r->left);
    int ri=traverse(r->right);
    ans=max(ans,1+l+ri);
    return 1+max(l,ri);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        traverse(root);
        return ans-1;
    }
};