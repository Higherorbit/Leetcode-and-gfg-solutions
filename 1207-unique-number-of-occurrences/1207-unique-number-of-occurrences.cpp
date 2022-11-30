class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto &i:arr){
            mp[i]++;
        }
        set<int>s;
        for(auto &x:mp){
            s.insert(x.second);
        }
        return (s.size()==mp.size());
    }
};