class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans*=10;
            if(s[i]=='6'){
                ans+=6;
            }
            else{
                ans+=9;
            }
        }
        return ans;
        
    }
};