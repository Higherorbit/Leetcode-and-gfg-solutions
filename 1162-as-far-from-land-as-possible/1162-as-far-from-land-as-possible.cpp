class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        bool c=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i+1,j));          
                    q.push(make_pair(i-1,j));
                    q.push(make_pair(i,j+1));
                    q.push(make_pair(i,j-1));
                }
                else{
                    c=true;
                }
            }
        }
        if(q.empty() or !c){
            return -1;
        }
        int visited[n][m];
        int steps=1;
        memset(visited,0,sizeof(visited));
        while(!q.empty()){
            int N=q.size();
            for(int k=0;k<N;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i>=0 and j>=0 and i<n and j<m and visited[i][j]==0 and grid[i][j]==0){
                    visited[i][j]=1;
                    grid[i][j]=steps;
                    q.push(make_pair(i+1,j));          
                    q.push(make_pair(i-1,j));
                    q.push(make_pair(i,j+1));
                    q.push(make_pair(i,j-1));
                }
            }
            ++steps;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,grid[i][j]);
            }
        }
        return ans;
    }
};