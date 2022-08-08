class KthLargest {
public:
    int k;
    multiset<int>s;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto &x:nums){
            s.insert(x);
        }        
    }
    
    int add(int val) {
        //O(1);
        // log(n)
        // nlog(n)
        // 1 2 3 4 5 n-k+1
        s.insert(val);
        int n=s.size();
        int cnt=0;
        for(auto &x:s){
            cnt++;
            if(cnt==n-k+1){
                return x;
            }
        }
        return -1;      
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */