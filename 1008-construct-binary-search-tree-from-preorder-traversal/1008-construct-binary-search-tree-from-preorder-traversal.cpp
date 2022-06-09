class Solution {
public:
    TreeNode* solve(vector<int>&v , int l, int r){
        if(l==r){
            return new TreeNode(v[l]);
        }
        if(l>r){
            return NULL;
        }
        TreeNode* root=new TreeNode(v[l]);
        int i=l;
        for(i;i<=r;i++){
            if(v[i]>v[l]){
                break;
            }
        }
        root->left=solve(v,l+1,i-1);
        root->right=solve(v,i,r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>&v) {
        return solve(v,0,v.size()-1);
    }
};