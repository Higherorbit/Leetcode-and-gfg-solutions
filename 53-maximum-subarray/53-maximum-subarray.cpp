class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,0);
        dp[0]=v[0];
        for(int i=1;i<n;i++){
            dp[i]=max(v[i],v[i]+dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};