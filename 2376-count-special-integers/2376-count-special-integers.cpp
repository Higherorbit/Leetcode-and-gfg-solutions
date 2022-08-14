class Solution {
public:
    // pos=9 digits se kam
//
// pos,sum,tight
// sum=8*9=72
// int dp[pos][mask][tight]
int dp[11][1024][2];
int g(string s,int pos,int mask,int tight){
    if(pos==s.size()){
        return (mask!=0);
    }
    if(dp[pos][mask][tight]!=-1){
        return dp[pos][mask][tight];
    }
    int res=0;
    if(tight==1){
        int limit=s[pos]-'0';
        for(int i=0;i<=limit;i++){
            if(mask&(1<<i)){
                continue;
            }
            int newmask=(mask==0 and i==0? (mask):(mask|(1<<i)));
            if(i==limit){
                res+=g(s,pos+1,newmask,1);
            }
            else{
                res+=g(s,pos+1,newmask,0);
            }
        }
    }
    else{
        for(int i=0;i<=9;i++){
            if(mask&(1<<i)){
                continue;
            }
            int newmask=(mask==0 and i==0? (mask):(mask|(1<<i)));
            res+=g(s,pos+1,newmask,0);
        }
    }
    return dp[pos][mask][tight]=res;
}
    int countSpecialNumbers(int n) {
        memset(dp,-1,sizeof(dp));
        return g(to_string(n),0,0,1);
    }
};