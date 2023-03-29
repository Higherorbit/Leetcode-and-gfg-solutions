class Solution {
public:
    int rows;
    int col;
    void dfs(vector<vector<int>>&v,int i,int j){
        if(i<0 or j<0 or i>=rows or j>=col ){
            return ;
        }
        if(v[i][j]!=1){
            return ;
        }
        v[i][j]=-2;
        dfs(v,i+1,j);
        dfs(v,i,j+1);
        dfs(v,i-1,j);
        dfs(v,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& v) {
        if(v.size()==0){
            return 0;
        }
        rows=v.size();
        col=v[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(i==0 or j==0 or i==rows-1 or j==col-1){
                    dfs(v,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(v[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};