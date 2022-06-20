class Solution {
public:
    struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
    int findTargetSumWays(vector<int>& v, int s) {
        int n=v.size();
        unordered_map<int,int,custom_hash> mp;
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