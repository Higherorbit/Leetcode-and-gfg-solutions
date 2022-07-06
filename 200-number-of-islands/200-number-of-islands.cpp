class Solution {
public:
    int visited[302][302];
    int n;
    int m;
    int cnt;
    void dfs(int i, int j,vector<vector<char>>& grid){
        if(i<0 or j<0 or i>=n or j>=m){
            return ;
        }
        if(visited[i][j] or grid[i][j]=='0'){
            return ;
        }
        visited[i][j]=1;
        cnt++;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0){
            return 0;
        }
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
                if(grid[i][j]=='1' and visited[i][j]==0){
                    dfs(i,j,grid);
                    ans++;
                    cnt=0;
                }
            }
        }
        return ans;
    }
};