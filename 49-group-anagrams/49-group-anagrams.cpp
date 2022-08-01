#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map<vector<int>,vector<string>>mp;
        for(string x:str){
            vector<int>freq(26,0);
            for(auto i:x){
                freq[i-'a']++;
            }
            mp[freq].push_back((x));
        }
        vector<vector<string>>ans;
        for(auto x:mp){
            vector<string>temp;
            for(auto i:x.second){
                temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};