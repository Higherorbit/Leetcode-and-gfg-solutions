class Solution {
public:
    string removeStars(string s) {
        stack<int>st;
        int n=s.size();
        set<int>matle;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                matle.insert(i);
                if(!st.empty()){
                    matle.insert(st.top());
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(!matle.count(i)){
                ans+=s[i];
            }
        }
        return ans;
    }
};