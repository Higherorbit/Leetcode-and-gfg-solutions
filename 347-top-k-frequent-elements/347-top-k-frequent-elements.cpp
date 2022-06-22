class Solution {
public:
    static bool comp(pair<int,int>a, pair<int,int>b){
        if(a.first!=b.first){
            return a.first>b.first;
        }
        else{
            return a.second>=b.first;
        }
    }
    vector<int> topKFrequent(vector<int>& v, int k) {
        map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
        }
        vector<pair<int,int>>mm;
        for(auto x:mp){
            mm.push_back({x.second,x.first});
        }
        sort(mm.rbegin(),mm.rend());
        
        vector<int>ans;
        for(auto x:mm){
            if(k){
                k--;
                ans.push_back(x.second);
            }
            else break;
        }
        return ans;
    }
};