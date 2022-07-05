class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        unordered_set<int>s;
        int n=v.size();
        for(int i=0;i<n;i++){
            s.insert(v[i]);
        }
        int ans=0;
        int curr=1;
        for(int i=0;i<n;i++){
            if(!s.count(v[i]-1)){
                while(s.count(++v[i])){
                    curr++;
                }
                ans=max(ans,curr);
            }
            curr=1;
        }
        
        return ans;
    }
};