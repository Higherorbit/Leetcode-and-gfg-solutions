class linkedlist{
    public:
    TreeNode* head;
    TreeNode* tail;
};
class Solution {
public:
    vector<int> v;
    void traverse(TreeNode* root){
        if(root==NULL){
            return ;
        }
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL){
            return ;
        }
        traverse(root);
        root->val=v[0];
        TreeNode* temp=root;        
        for(int i=1;i<v.size();i++){
            TreeNode* n=new TreeNode();
            n->val=v[i];
            temp->right=n;
            temp->left=NULL;
            temp=n;
        }
    }
//     linkedlist traverse(TreeNode* root){
//         linkedlist l;
//         if(root->right==NULL and root->left==NULL){
//             l.head=root;
//             l.tail=root;
//         }
//         else if(root->right==NULL and root->left){
//             linkedlist ll=traverse(root->left);
//             ll.tail->right=root;
//             l.head=ll.head;
//             l.tail=root;
//         }
//         else if(root->right and root->left==NULL){
//             linkedlist rl=traverse(root->right);
//             root->right=rl.head;
//             l.head=root;
//             l.tail=rl.tail;
//         }
//         else{
//             linkedlist ll=traverse(root->left);
//             linkedlist rl=traverse(root->right);
//             ll.tail->right=root;
//             root->right=rl.head;
//             l.head=ll.head;
//             l.tail=rl.tail;
//         }
//         return l;
//     }
    
//     void flatten(TreeNode* root) {
//         if(root==NULL){
//             return ;
//         }
//         auto ans=traverse(root);
//         root=ans.head;
//         return ;
//     }
};