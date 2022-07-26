class node{
    public:
    int sum;
    bool isBst;
    int mini;
    int maxi;
    node(){
        sum=0;
        isBst=true;
        mini=INT_MAX;
        maxi=INT_MIN;
    }
};
class Solution {
public:
    
    int ans=0;
    node solve(TreeNode* root){
        if(root==NULL){
            return node();
        }
        node r;
        node rl=solve(root->left);
        node rr=solve(root->right);
        if(rl.isBst==false or rr.isBst==false or root->val>=rr.mini or root->val<=rl.maxi){
            r.isBst=false;
            r.sum=max(rl.sum,rr.sum);
        }
        else{
            r.isBst=true;
            r.sum=root->val+rl.sum+rr.sum;
            ans=max(ans,r.sum);
            r.mini=min(root->val,rl.mini);
            r.maxi=max(root->val,rr.maxi);
        }
        return r;
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};