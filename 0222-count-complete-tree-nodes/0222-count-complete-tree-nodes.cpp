class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=0;
        int rh=0;
        TreeNode* t=root;
        while(t!=NULL){
            lh++;
            t=t->left;
        }
        t=root;
        while(t!=NULL){
            rh++;
            t=t->right;
        }
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};