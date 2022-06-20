class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        map<int,int>mp;       
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(mp.count(target-nums[i]) and i!=mp[(int)target-nums[i]]){
                v.push_back(i);
                int k=mp[(int)target-nums[i]];
                v.push_back(k);
                break;
            }
        }
        return v;
    }
};