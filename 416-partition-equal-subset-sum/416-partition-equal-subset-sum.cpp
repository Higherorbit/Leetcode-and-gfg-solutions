class Solution {
public:
    bool canPartition(vector<int>& v) {
        int sum=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        if(sum&1){
            return false;
        }
        sum/=2;
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=v[i-1])
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-v[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
        
    }
};