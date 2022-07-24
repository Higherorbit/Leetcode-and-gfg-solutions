class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans=0;
        map<int, long long>mp;
        for(auto x:unordered_set<int>(begin(nums),end(nums))){
            mp[__builtin_popcount(x)]++;
        }
        for(int i=1;i<30;i++){
            for(int j=1;j<30;j++){
                if(i+j>=k){
                    ans+=mp[i]*mp[j];
                }
            }
        }
        return ans;
        
    }
};