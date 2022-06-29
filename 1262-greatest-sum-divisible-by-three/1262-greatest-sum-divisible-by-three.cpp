class Solution {
public:
    int maxSumDivThree(vector<int>& v) {
        vector<int>dpp(3,0);
        for(int i=0;i<v.size();i++){
            auto dp=dpp;
            for(int j=0;j<3;j++){
                dp[(v[i]+dpp[j])%3]=max(dp[(v[i]+dpp[j])%3],v[i]+dpp[j]);
            }
            dpp=dp;
        }
        
        return dpp[0];
    }
};