class Solution {
public:
    int numSquares(int sum) {
        //dp ka tha yeh
        //first lets calculate all the possible sqs less than n
        vector<int>sq;
        for(int i=1;i*i<=sum;i++){
            sq.push_back(i*i);
        }
        int n=sq.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int j=1;j<=sum;j++){
            dp[1][j]=j;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(sq[i-1]<=j){
                    dp[i][j]=min(dp[i][j-sq[i-1]]+1,dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};