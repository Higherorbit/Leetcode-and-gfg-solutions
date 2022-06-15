class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n=v.size();
        
        vector<int>divCount(n,1);//count of number of divisors ending at i
        vector<int>prev(n,-1);// to keep the record of prev divisor
        
        sort(v.begin(),v.end());
        int max_index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]%v[j]==0){
                    if(divCount[i]<divCount[j]+1){
                        divCount[i]=divCount[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(divCount[max_index]<divCount[i]){
                max_index=i;
            }
        }
        int k=max_index;
        vector<int>ans;
        while(k>=0){
            ans.push_back(v[k]);
            k=prev[k];
        }
        reverse(ans.begin(),ans.end());
        return ans;  
        
        
        
    }
};