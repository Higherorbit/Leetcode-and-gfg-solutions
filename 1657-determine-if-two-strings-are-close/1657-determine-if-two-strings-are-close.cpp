class Solution {
public:
    bool closeStrings(string s, string t) {
        map<int,char> mp1, mp2;
        set<char>s1,s2;
        for(auto &x:s){
            mp1[x]++;
            s1.insert(x);
        }
        for(auto &x:t){
            mp2[x]++;
            s2.insert(x);
        }
        vector<int>v1,v2;
        for(auto &x:mp1){
            v1.push_back(x.second);
        }
        for(auto &x:mp2){
            v2.push_back(x.second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return (v1==v2 and s1==s2);
        
    }
};