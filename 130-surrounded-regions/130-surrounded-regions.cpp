class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<char>>&v, int i,int j){
        if(i<0 or j<0 or i>=n or j>=m){
            return ;
        }
        if(v[i][j]!='O'){
            return ;
        }
        v[i][j]='A';
        dfs(v,i+1,j);
        dfs(v,i,j+1);
        dfs(v,i-1,j);
        dfs(v,i,j-1);
    }
    void solve(vector<vector<char>>& v) {
        n=v.size();
        m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    dfs(v,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='A'){
                    v[i][j]='O';
                }
                else{
                    v[i][j]='X';
                }
            }
        }
        
        
    }
};