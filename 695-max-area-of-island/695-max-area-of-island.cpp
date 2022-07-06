class Solution {
public:
    bool visited[52][52];
    int n;
    int m;
    int cur;
    void dfs(int i, int j,vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=n or j>=m){
            return ;
        }
        if(grid[i][j]==0 or visited[i][j]==1){
            return ;
        }
        visited[i][j]=1;
        cur++;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);         
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 and grid[i][j]==1){
                    cur=0;
                    dfs(i,j,grid);
                    ans=max(ans,cur);
                }
            }
        }
        return ans;
    }
};