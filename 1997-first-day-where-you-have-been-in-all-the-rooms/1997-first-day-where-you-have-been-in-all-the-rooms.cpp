class Solution {
public:
    const int mod=1e9+7;
    int firstDayBeenInAllRooms(vector<int>& v){
        #define int long long 
        int n=v.size();
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            dp[i]=(dp[i-1]+2+dp[i-1]-dp[v[i-1]]+mod);
            dp[i]%=mod;
        }
        #undef int
        return dp[n-1];
    }
};