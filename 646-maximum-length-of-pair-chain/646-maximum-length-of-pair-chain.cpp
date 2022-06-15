class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
    sort(v.begin(),v.end());
    // for(int i=0;i<n;i++){
    //     cout<<v[i].first<<" ";
    //     cout<<v[i].second<<endl;
    // }
    int n=v.size();
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(v[j][1]<v[i][0]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    sort(dp,dp+n);
    return dp[n-1];
    }
};