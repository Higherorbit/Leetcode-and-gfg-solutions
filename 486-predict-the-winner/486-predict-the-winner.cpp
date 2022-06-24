class Solution {
public:
    bool PredictTheWinner(vector<int>& v) {
        int n=v.size();
        pair<int,int> dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i].first=v[i];
            dp[i][i].second=0;
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1].first=max(v[i],v[i+1]);
            dp[i][i+1].second=min(v[i],v[i+1]);
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j=i+k-1;
                if(v[i]+dp[i+1][j].second>=v[j]+dp[i][j-1].second){
                    dp[i][j].first=v[i]+dp[i+1][j].second;
                    dp[i][j].second=dp[i+1][j].first;
                }
                else{
                    dp[i][j].first=v[j]+dp[i][j-1].second;
                    dp[i][j].second=dp[i][j-1].first;
                }
            }
        }
        return dp[0][n-1].first>=dp[0][n-1].second;
    }
};