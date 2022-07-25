class Solution {
public:
    int count(vector<int>& l, vector<int>& r,int root){
        // dfs from the root to see if all the elements are visited 
        if(root==-1){
            return 0;
        }
        return 1+count(l,r,l[root])+count(l,r,r[root]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        // checking the indegreee
        // except the root all nodes must have indegree 1
        vector<int>inDeg(n,0);
        for(int i=0;i<l.size();i++){
            if(l[i]!=-1){
                inDeg[l[i]]++;
                if(inDeg[l[i]]>1){
                    return false;
                }
            }
            if(r[i]!=-1){
                inDeg[r[i]]++;
                if(inDeg[r[i]]>1){
                    return false;
                }
            }
        }
        //Now lets find the root
        // the one with inDeg 0
        int root=-1;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                if(root!=-1){// checking for mutliple roots
                    return false;
                }
                root=i;
            }
        }
        return count(l,r,root)==n;
    }
};