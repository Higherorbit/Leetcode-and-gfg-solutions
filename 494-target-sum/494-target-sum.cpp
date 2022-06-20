class Solution {
public:
    int findTargetSumWays(vector<int>& v, int s) {
        int n=v.size();
        unordered_map<int,int>mp;
        mp[v[0]]++;
        mp[-v[0]]++;
        for(int i=1;i<n;i++){
            auto t=mp;
            mp.clear();
            for(auto x:t){
                mp[x.first+v[i]]+=x.second;
                mp[x.first-v[i]]+=x.second;
            }
        }
        return mp[s];
        
    }
};