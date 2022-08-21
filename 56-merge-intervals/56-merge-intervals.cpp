class Solution {
public:
    static bool comp(vector<int>& p1, vector<int> &p2){
        if(p1[0]!=p2[0]){
            return p1[0]<p2[0];
        }
        return p1[1]<p2[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        vector<vector<int>>ans;
        int l=v[0][0];
        int r=v[0][1];
        for(auto x:v){
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        for(int i=1;i<v.size();i++){
            if(v[i][0]>r){
                ans.push_back({l,r});
                l=v[i][0];
                r=v[i][1];
            }
            else{
                if(r<v[i][1])
                r=v[i][1];
            }
        }
        // cout<<r<<endl;
        // cout<<ans[ans.size()-1][1]<<endl;
        // if(ans.size()==0 or ans[ans.size()-1][1]<r){
            ans.push_back({l,r});
        // }
        return ans;
    }
};