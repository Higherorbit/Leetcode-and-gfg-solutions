class Solution {
    int ans;
    public int excess(TreeNode root){
        if(root==null){
            return 0;
        }
        int l=(excess(root.left));
        int r=(excess(root.right));
        ans+=Math.abs(l)+Math.abs(r);
        return (l)+(r)+root.val-1;
    }
    public int distributeCoins(TreeNode root) {
        ans=0;
        excess(root);
        return ans;
    }
}