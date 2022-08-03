class Solution {
public:
    int subarraySum(vector<int>& v, int k){
        int n=v.size();
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(mp.count(sum-k)){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;        
    }
};