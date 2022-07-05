class Solution {
public:
    int maximumGap(vector<int>& v) {
        int n=v.size();
        if(v.size()<2){
            return 0;
        }
        sort(v.begin(),v.end());
        int ans=v[1]-v[0];
        for(int i=2;i<v.size();i++){
            ans=max(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};