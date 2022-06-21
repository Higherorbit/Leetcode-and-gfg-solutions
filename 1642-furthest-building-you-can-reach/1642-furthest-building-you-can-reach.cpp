class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        priority_queue<int, vector<int>, greater<int> >pq;
        int n=v.size();
        for(int i=1;i<n;i++){
            int d=v[i]-v[i-1];
            if(d>0){
                pq.push(d);
                if(pq.size()>l){
                    b-=pq.top();
                    pq.pop();
                }
                if(b<0){
                    return i-1;
                }
            }
        }
        return n-1;
    }
};