class Solution {
public:
    unordered_map<int,int>mp;
    bool ans=false;
    void traverse(TreeNode* root, int k){
        if(root==NULL){
            return ;
        }
        if(mp.count((k-root->val))){
            ans=true;
            return ;
        }
        mp[root->val]++;
        traverse(root->left,k);
        traverse(root->right,k);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        ans=false;
        mp.clear();
        traverse(root,k);
        return ans;
        
    }
};