class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL){
            if(q==NULL){
                return true;
            }
            else return false;
        }
        if(q==NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};