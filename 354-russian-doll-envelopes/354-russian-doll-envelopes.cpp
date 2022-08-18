class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
    int maxEnvelopes(vector<vector<int>>& v) {
        vector<int>dp;
        int i=0;
        int n=v.size();
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++){
            auto it=lower_bound(dp.begin(),dp.end(),v[i][1]);
            if(it==dp.end()){
                dp.push_back(v[i][1]);
            }
            else{
                *it=v[i][1];
            }
        }
        return dp.size();
    }
};