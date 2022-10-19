class Solution {
public:
    static bool comp(pair<int,string>p1,pair<int,string>p2){
        if(p1.first!=p2.first){
            return p1.first>p2.first;
        }
        return p1.second<p2.second;
    }
    vector<string> topKFrequent(vector<string>& v, int k) {
        map<string,int>mp;
        for(auto &x:v){
            mp[x]++;
        }
        vector<pair<int,string>>pq;
        for(auto &x:mp){
            pq.push_back({x.second,x.first});
        }
        sort(pq.begin(),pq.end(),comp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq[i].second);
        }
        return ans;
    }
};