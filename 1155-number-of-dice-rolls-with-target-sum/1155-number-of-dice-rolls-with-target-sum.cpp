class Solution {
public:
    const int mod=1e9+7;
    int numRollsToTarget(int n, int k, int t) {
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        for(int j=1;j<=t;j++){
            dp[1][j]=j<=k;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=t;j++){
                for(int k1=1;k1<=k;k1++){
                    if(k1<=j){
                        dp[i][j]+=dp[i-1][j-k1];
                        dp[i][j]%=mod;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return dp[n][t]%mod;
        
    }
};