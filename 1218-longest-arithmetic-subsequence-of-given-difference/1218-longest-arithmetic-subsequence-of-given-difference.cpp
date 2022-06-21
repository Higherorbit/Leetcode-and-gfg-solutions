class Solution {
public:
    int longestSubsequence(vector<int>& v, int difference) {
        int n=v.size();
        map<int,int>dp;
        int ans=0;
        dp[v[0]]=1;
        for(int i=1;i<n;i++){
            dp[v[i]]=1+dp[v[i]-difference];
            // cout<<dp[v[i]]<<" ";
            ans=max(ans,dp[v[i]]);
        }
        return ans;
    }
};