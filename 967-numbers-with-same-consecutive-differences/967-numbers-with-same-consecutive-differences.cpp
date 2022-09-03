class Solution {
public:
    
    void solve(string s, int pos, int n, int k,vector<int>&v){
        if(pos==n){
            v.push_back(stoi(s));
            return ;
        }
        if(pos==0){
            for(int i=1;i<=9;i++){
                solve(s+to_string(i),pos+1,n,k,v);
            }
        }
        else{
            int l=s[s.size()-1]-'0';
            if(l+k<=9){
                solve(s+to_string(l+k),pos+1,n,k,v);
            }
            if(l-k>=0){
                solve(s+to_string(l-k),pos+1,n,k,v);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s="";
        vector<int>v;
        int pos=0;
        solve(s,0,n,k,v);
        v.erase(std::unique(v.begin(), v.end()), v.end());
        
        return v;
    }
};