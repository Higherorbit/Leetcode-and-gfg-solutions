class Solution {
public:
    bool check(vector<int>w,int d, int r){
        int cnt=1,t=0;
        for(int i=0;i<w.size();i++){
            t+=w[i];
            if(t>r){
                cnt++;
                t=w[i];
            }
        }
        return cnt<=d;
    }
    int shipWithinDays(vector<int>& w, int d) {
        //simple binary search problem it is
        // if least weight is w, w+1 pe it will also work.
        int sum=0;
        int m=0;
        int n=w.size();
        for(int i=0;i<n;i++){
            sum+=w[i];
            m=max(m,w[i]);
        }
        int l=m,h=sum;
        int ans=sum+1;
        // sort(w.begin(),w.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            // cout<<mid<<endl;
            if(check(w,d,mid)){
                // cout<<"YEs"<<endl;
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};