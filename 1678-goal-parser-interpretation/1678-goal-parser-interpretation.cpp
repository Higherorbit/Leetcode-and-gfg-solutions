class Solution {
public:
    string interpret(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='G'){
                ans+='G';
            }
            else if(s[i]=='('){
                if(s[i+1]==')'){
                    ans+="o";
                }
                else{
                    ans+="al";
                }
            }            
        }
        return ans;
        
    }
};