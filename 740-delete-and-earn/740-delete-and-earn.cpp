class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        int m=*max_element(v.begin(),v.end());
        int dp[m+1]        ;
        memset(dp,0,sizeof(dp));
        map<int,int> count;
        for(int i=0;i<v.size();i++){
            count[v[i]]++;
        }
        for(int i=1;i<=m;i++){
            int k=max(i-2,0);
            dp[i]=max(dp[i-1],dp[k]+i*count[i]);
        }
        return dp[m];
    }
};