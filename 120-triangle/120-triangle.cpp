class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++){
                if(i==0 or j==0){
                    dp[i][j]=INT_MAX;
                }
            }
        dp[1][1]=v[0][0];
        for(int j=2;j<=n;j++){
            dp[1][j]=INT_MAX;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+v[i-1][j-1];
            }
            for(int k=i+1;k<=n;k++){
                dp[i][k]=INT_MAX;
            }
        }
        int ans=INT_MAX;
        for(int j=1;j<=n;j++){
            ans=min(ans,dp[n][j]);
        }
        return ans;
        
    }
};