/*
we have 2 choices available
1. we have stock on day i,
    - we bought it today 
        dp[i][1]=dp[i-2][0]-v[i];
    -we are carry forwarding it
        dp[i][1]=dp[i-1][1];
2. We dont have it today
    - we sold it today
        dp[i][0]=d[i-1][1]+v[i];
    - carry forwarding it
        dp[i][0]=dp[i-1][0];
*/
class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        if(n==1){
            return 0;
        }
        int dp[n][2];
        dp[0][0]=0;
        dp[0][1]=-v[0];
        int i=0;
        dp[1][0]=max(dp[0][0],dp[0][1]+v[1]);
        dp[1][1]=max(dp[0][1],-v[1]);
        for(int i=2;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+v[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][0]-v[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
        
    }
};