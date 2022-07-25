//this is O(n)
//we get the height right on traversing
class Solution {
public:
    int check(TreeNode* r){
        if(r==NULL){
            return 0;
        }
        int lh=check(r->left);
        if(lh==-1){
            return lh;
        }
        int rh=check(r->right);
        if(rh==-1){
            return rh;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return check(root)!=-1;
        
    }
};