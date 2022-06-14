class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        for(int i=1;i<n;i++){
            int cur_max=0;
            for(int j=i;j>=0;j--){
                if(v[j]<v[i]){
                    cur_max=max(cur_max,dp[j]);
                }
            }
            dp[i]=max(dp[i],1+cur_max);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;        
    }
};