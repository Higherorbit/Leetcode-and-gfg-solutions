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
    int preIndex;
    TreeNode* solve(vector<int>& in, vector<int>& pr,int ins,int ine){
        if(ins>ine or preIndex==-1){
            return NULL;
        }
        TreeNode* root=new TreeNode(pr[preIndex--]);
        int ind=0;
        for(int i=ins;i<=ine;i++){
            if(in[i]==root->val){
                ind=i;
                break;
            }
        }
        cout<<ind<<endl;
        root->right=solve(in,pr,ind+1,ine);
        root->left=solve(in,pr,ins,ind-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pr) {
        if(pr.size()==0){
            return NULL;
        }
        preIndex=pr.size()-1;
        TreeNode* ans=solve(in,pr,0,in.size()-1);
        return ans;
    }
};