class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_set<int>x;
        unordered_set<int>y;
        //O(n^2) hai yeh
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            // if(x.count(i)){
                for(int j=0;j<m;j++){
                    if(x.count(i) or y.count(j))
                        mat[i][j]=0;
                }
            // }
        }
        
    }
};