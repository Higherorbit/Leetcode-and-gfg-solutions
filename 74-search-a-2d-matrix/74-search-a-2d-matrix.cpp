class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int k) {
        if(k<mat[0][0])return false;
        vector<int> col;
        for(int i=0;i<mat.size();i++){
            col.push_back(mat[i][0]);
        }
        int i=lower_bound(col.begin(),col.end(),k)-col.begin();
        if(i!=mat.size() and mat[i][0]==k){
            return true;
        }
        i--;
        // cout<<i<<endl;
        vector<int> row;
        for(int j=0;j<mat[0].size();j++){
            row.push_back(mat[i][j]);
        }
        int j=lower_bound(row.begin(),row.end(),k)-row.begin();
        // cout<<i<<" "<<j<<endl;
        if(j==mat[0].size()){
            return false;
        }
        return row[j]==k;   
    }
};