class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int>s;
        if(nums.size()<2){
            return 0;
        }
        for(auto n:nums) s.insert(n);
        vector<int>v;
        for(auto x:s) v.push_back(x);
        if(v.size()==1){
            return 0;
        }
        int ans=v[1]-v[0];
        for(int i=2;i<v.size();i++){
            ans=max(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};