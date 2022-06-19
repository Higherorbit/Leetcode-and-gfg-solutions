class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=1;j<=m;j++){
            dp[1][j]=1;
        }
        for(int i=1;i<=n;i++){
            dp[i][1]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n][m];
        
    }
};