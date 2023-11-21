class Solution {
public:
    int n;
    int m;
    bool dfs(vector<vector<int>>& grid,int i, int j){
        if(grid[i][j]!=0){
            return true;
        }
        if(i==0 or j==0 or i>=n-1 or j>=m-1){
            return false;
        }
        grid[i][j]=-1;
        return dfs(grid,i+1,j)&dfs(grid,i,j+1)&dfs(grid,i-1,j)&dfs(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dfs(grid,0,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};