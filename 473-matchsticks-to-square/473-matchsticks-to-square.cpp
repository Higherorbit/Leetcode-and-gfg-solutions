class Solution {
public:
    const int N=4;
    vector<int>sum;
    int reqSum;
    bool dfs(vector<int>&v, int index){
        if(index==v.size()){
            return sum[0]==sum[1] and sum[1]==sum[2] and sum[2]==sum[3];
        }
        for(int i=0;i<4;i++){
            if(sum[i]+v[index]<=reqSum){
                sum[i]+=v[index];
                if(dfs(v,index+1)){
                    return true;
                }
                sum[i]-=v[index];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& v) {
        int s=0;
        for(auto x:v)s+=x;
        if(s%4!=0)return false;
        reqSum=s/4;
        // we need to check if there are 4 subsequences of equal sum.
        // let's check all the possiblities
        sum.resize(4);
        for(int i=0;i<4;i++){
            sum[i]=0;
        }
        sort(v.rbegin(),v.rend());
        return dfs(v,0);
        
        
    }
};