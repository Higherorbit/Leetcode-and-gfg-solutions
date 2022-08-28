class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            vector<int>v;
            int x=i;
            int y=0;
            while(x<n and y<m){
                v.push_back(grid[x++][y++]);
            }
            sort(v.begin(),v.end());
            x=i;
            y=0;
            int j=0;
            while(x<n and y<m){
                grid[x++][y++]=v[j++];
            }
        }
        for(int i=1;i<m;i++){
            vector<int>v;
            int x=0;
            int y=i;
            while(y<m and x<n){
                v.push_back(grid[x++][y++]);
            }
            sort(v.begin(),v.end());
            x=0;
            y=i;
            int j=0;
            while(y<m and x<n){
                grid[x++][y++]=v[j++];
            }
        }
        return grid;
    }
};