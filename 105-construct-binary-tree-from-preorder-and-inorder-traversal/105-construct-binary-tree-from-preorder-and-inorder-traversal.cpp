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
    int preIndex=0;
    TreeNode* solve(vector<int>& pr, vector<int>& in,int ins,int ine){
        if(ine<ins){
            return NULL;
        }
        if(ins==ine){
            return new TreeNode(pr[preIndex++]);
        }
        TreeNode* root=new TreeNode(pr[preIndex++]);
        int ind=0;
        for(int i=ins;i<=ine;i++){
            if(in[i]==root->val){
                ind=i;
                break;
            }
        }
        root->left=solve(pr,in,ins,ind-1);
        root->right=solve(pr,in,ind+1,ine);
        return root;
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        if(pr.size()==0){
            return NULL;
        }
        TreeNode* ans=solve(pr,in,0,in.size()-1);
        return ans;
    }
};