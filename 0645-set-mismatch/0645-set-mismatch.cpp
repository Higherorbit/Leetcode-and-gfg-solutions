class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        map<int,int>mp;
        int n=v.size();
        int f=-1,s=-1;
        for(int i=0;i<n;i++){
            mp[v[i]]++;
            if(mp[v[i]]==2){
                f=v[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(!mp.count(i)){
                s=i;
                break;
            }
        }
        return {f,s};
        
        
    }
};