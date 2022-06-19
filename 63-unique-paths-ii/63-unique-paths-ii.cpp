class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=1;j<=m;j++){
            if(v[0][j-1]==1){
                break;
            }
            dp[1][j]=1;
        }
        for(int i=1;i<=n;i++){
            if(v[i-1][0]==1){
                break;
            }
            dp[i][1]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                if(v[i-1][j-1]){
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};