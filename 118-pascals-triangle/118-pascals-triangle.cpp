class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> f(1,1);
        vector<vector<int>>ans;
        ans.push_back(f);
        for(int i=2;i<=numRows;i++){
            vector<int>temp(i,1);
            for(int j=1;j<=i-2;j++){
                temp[j]=f[j-1]+f[j];
            }
            f=temp;
            ans.push_back(f);
            
        }
        return ans;
    }
};