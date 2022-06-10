class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.size();
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            set<char>ss;
            for(int j=i;j<n;j++){
                if(ss.count(s[j])==0){
                    ss.insert(s[j]);
                }
                else{
                    break;
                }
                ans=max(ans,(int)ss.size());
            }
        }
        return ans;
    }
};