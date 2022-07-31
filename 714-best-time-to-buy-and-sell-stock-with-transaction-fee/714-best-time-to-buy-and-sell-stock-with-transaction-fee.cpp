class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        int dp[n][2];
        if(n==1){
            return 0;
        }
        //dp[i][0] means we dont have stock ont that day
        //dp[i][1] means we have
        dp[0][0]=0;
        dp[0][1]=-v[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+v[i]-fee);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-v[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
        
        
        
        
        
        // dp[0][0]=0;
        // dp[0][1]=-v[0];
        // dp[1][0]=max(dp[0][0],dp[0][1]+v[1]-fee);
        // dp[1][1]=max(dp[0][1],-v[1]);
        // for(int i=2;i<n;i++){
        //     dp[i][0]=max(dp[i-1][0],dp[i-1][1]+v[i]-fee);
        //     dp[i][1]=max(dp[i-1][1],dp[i-1][0]-v[i]);
        // }
        // return max(dp[n-1][0],dp[n-1][1]);
        
    }
};