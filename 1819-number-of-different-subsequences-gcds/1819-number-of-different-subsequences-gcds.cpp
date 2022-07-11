class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n=nums.size();
        vector<bool>present(200001,false);
        for(int i=0;i<n;i++){
            present[nums[i]]=true;
        }
        int ans=0;
        for(int i=1;i<=200000;i++){
            int ok=-1;
            if(present[i]) ans++;
            else{
                for(int j=i+i;j<=200000;j+=i){
                    if(!present[j]){
                        continue;
                    }
                    if(ok==-1){
                        ok=j;                        
                    }
                    else{
                        ok=__gcd(ok,j);
                    }
                }
                if(ok==i){
                    ans++;
                }
            }
        }
        return ans;
        
    }
    
};