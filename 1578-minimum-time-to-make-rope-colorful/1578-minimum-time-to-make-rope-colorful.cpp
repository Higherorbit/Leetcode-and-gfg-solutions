class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n=v.size();
        int ans=0;
        vector<int>c;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                if(c.size()==0){
                    c.push_back(v[i-1]);
                    c.push_back(v[i]);
                }
                else{
                    c.push_back(v[i]);
                }
            }
            else{
                if(c.size()){
                    sort(c.begin(),c.end());
                    int N=c.size();
                    for(int j=0;j<N-1;j++){
                        ans+=c[j];
                    }
                    c.clear();
                }
            }
        }
        if(c.size()){
                    sort(c.begin(),c.end());
                    int N=c.size();
                    for(int j=0;j<N-1;j++){
                        ans+=c[j];
                    }
                    c.clear();
                }
        

        return ans;
        
    }
};