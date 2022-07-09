class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i+1,j));          
                    q.push(make_pair(i-1,j));
                    q.push(make_pair(i,j+1));
                    q.push(make_pair(i,j-1));
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        if(cnt==0){
            return 0;
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
                if(i>=0 and j>=0 and i<n and j<m and visited[i][j]==0 and grid[i][j]==1){
                    cnt--;
                    visited[i][j]=1;
                    grid[i][j]=steps;
                    if(cnt==0){
                        return steps;
                    }
                    q.push(make_pair(i+1,j));          
                    q.push(make_pair(i-1,j));
                    q.push(make_pair(i,j+1));
                    q.push(make_pair(i,j-1));
                }
            }
            ++steps;
        }
        if(cnt!=0){
            return -1;
        }
        else{
            return steps;
        }
        
        
    }
};