class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int key) {
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            if(key>=v[i][0]){
                if(lower_bound(v[i].begin(),v[i].end(),key)==v[i].end()){
                    continue;
                }
                if(key==*lower_bound(v[i].begin(),v[i].end(),key)){
                    return true;
                }
            }
        }
        return false;
    }
};