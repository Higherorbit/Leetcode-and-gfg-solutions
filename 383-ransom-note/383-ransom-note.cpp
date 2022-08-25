class Solution {
public:
    bool canConstruct(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;
        for(auto &x:s)m1[x]++;
        for(auto &x:t)m2[x]++;
        for(auto x:m1){
            cout<<x.first<<" "<<x.second<<endl;
            if(m2[x.first]<x.second){
                return false;
            }
        }
        return true;
    }
};