class Solution {
public:
    int coinChange(vector<int>& v, int sum) {
        int n=v.size();
        
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=INT_MAX-1;
                if(j==0){
                    dp[i][j]=0;
                }
                if(i==1){
                    if(j%v[0]==0){
                        dp[i][j]=j/v[0];
                    }
                }
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j>=v[i-1]){
                    dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=sum;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        if(dp[n][sum]==INT_MAX-1){
            return -1;
        }
        return dp[n][sum];
    }
};