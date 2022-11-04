class Solution {
public:
    string reverseVowels(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='i' or s[i]=='I' or s[i]=='e' or s[i]=='E'  or s[i]=='a' or s[i]=='A' or s[i]=='o' or s[i]=='O' or s[i]=='u' or s[i]=='U'){
                st.push(s[i]);
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='i' or s[i]=='I' or s[i]=='e' or s[i]=='E'  or s[i]=='a' or s[i]=='A' or s[i]=='o' or s[i]=='O' or s[i]=='u' or s[i]=='U'){
                s[i]=st.top();
                st.pop();
            }
        }
        return s;        
    }
};