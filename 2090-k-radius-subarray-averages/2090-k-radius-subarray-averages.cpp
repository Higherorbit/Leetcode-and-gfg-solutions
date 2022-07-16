class Solution {
public:
    vector<int> getAverages(vector<int>& v, int k) {
        int n=v.size();
        vector<int>ans(n,-1);
        deque<int> temp;
        long long sum=0;
        long long cnt=0;
        for(int i=0;i<n;i++){
            temp.push_back(v[i]);
            cnt++;
            sum+=v[i];
            if(cnt==2*k+1){
                ans[i-k]=sum/(2*k+1);
                cnt--;
                sum-=temp.front();
                temp.pop_front();
            }
        }
        return ans;
    }
};