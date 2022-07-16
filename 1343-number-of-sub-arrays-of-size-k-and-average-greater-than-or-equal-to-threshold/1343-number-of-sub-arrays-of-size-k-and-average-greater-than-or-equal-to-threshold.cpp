class Solution {
public:
    int numOfSubarrays(vector<int>& v, int k, int threshold) {
        int ans=0;
        // vector<int>temp;
        deque<int>temp;
        int cnt=0;
        double sum=0;
        for(int i=0;i<v.size();i++){
            temp.push_back(v[i]);
            cnt++;
            sum+=v[i];
            if(cnt==k){
                if(sum>=k*threshold){
                    ans++;
                }
                sum-=temp.front();
                temp.pop_front();
                cnt--;
            }
        }
        return ans;
        
    }
};