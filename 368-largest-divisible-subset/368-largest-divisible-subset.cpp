class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int m=0;
        int ind=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(v[i]%v[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(m<dp[i]){
                m=dp[i];
                ind=i;
            }
        }
        // for(auto &x:prev){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        vector<int>ans;
        while(prev[ind]!=-1){
            ans.push_back(v[ind]);
            ind=prev[ind];
        }
        ans.push_back(v[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};