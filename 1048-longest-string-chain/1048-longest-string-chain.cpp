class Solution {
public:
    static bool comp(string s,string t){
        return s.size()<t.size();
    }
    bool check(string t, string s){
        int i=0;
        int j=0;
        bool b=false;
        while(i<s.size() and j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                if(b){
                    return false;
                }
                b=true;
                i++;
            }            
        }
        return true;        
    }
    int longestStrChain(vector<string>& v) {
        int n=v.size();
        vector<int>dp(n,1);
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(v[j].size()==v[i].size()){
                    continue;
                }
                else if(v[j].size()+1==v[i].size()){
                    if(check(v[j],v[i])){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
                else{
                    break;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());       
    }
};