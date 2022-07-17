class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        for(int i=1;i<201;i++){
            if(i>v[0].size()){
                return ans;
            }
            char c=v[0][i-1];              
            for(int j=1;j<v.size();j++){
                if(i>v[j].size()){
                    return ans;
                }
                if(v[j][i-1]!=c)                {
                    return ans;
                }
            }
            ans+=c;
        }
        return ans;
        
    }
};