class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(v[i][j],v[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            auto &a=v[i];
            reverse(a.begin(),a.end());
        }
    }
};