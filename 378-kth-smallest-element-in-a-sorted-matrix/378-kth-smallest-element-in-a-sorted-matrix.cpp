class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        // gaani kehre suneyare to kadhai?
        //saal hogya c gehre tere katda tu kidiyan gallan ch a gyi?
        vector<int>v;
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v.push_back(mat[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};