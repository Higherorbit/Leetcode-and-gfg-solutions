class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        auto c=nums;
        sort(c.begin(),c.end());
        //o(n)
        map<int,int>mp;
        int n=nums.size();
        for(int i=n-1;i>=0 and k>0;i--){
            mp[c[i]]++;
            k--;
        }
        // for(auto [x,y]:mp)cout<<x<<" "<<y<<endl;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]){
                mp[nums[i]]--;
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
    }
};