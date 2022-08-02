class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        set<int>x;
        set<int>y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(x.count(i)){
                for(int j=0;j<m;j++){
                    mat[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(y.count(j)){
                for(int i=0;i<n;i++){
                    mat[i][j]=0;
                }
            }
        }
        
    }
};