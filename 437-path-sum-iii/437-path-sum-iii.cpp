class Solution {
public:
    int ans=0;
    #define int long long
    void solve(TreeNode* root, int s){
        if(root){
            if(root->val==s){
                ans++;
            }
            solve(root->left,s-root->val);
            solve(root->right,s-root->val);
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        solve(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        #undef int
        return ans;
        
    }
};