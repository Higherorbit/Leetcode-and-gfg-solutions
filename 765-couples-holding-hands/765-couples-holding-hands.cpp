class Solution {
public:
    int minSwapsCouples(vector<int>& v) {
        map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]=i;
        }
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i+=2){
            int s=v[i]^1;
            if(v[i+1]!=s){
                ans++;
                int ind=mp[s];
                swap(v[i+1],v[ind]);
                mp[v[ind]]=ind;
                mp[s]=i+1;
            }
            // for(auto x:v){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            // for(auto x:mp){
            //     cout<<x.first<<", "<<x.second<<" ";
            // }
            // cout<<endl;
        }
        return ans;
        
    }
};