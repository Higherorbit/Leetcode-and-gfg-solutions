class Solution {
public:
    void sortColors(vector<int>& v) {
        int l=0;
        int r=v.size()-1;
        int mid=0;
        int n=v.size();
        while(mid<=r){
            if(v[mid]==1){
                mid++;
            }
            else if(v[mid]==0){
                swap(v[l++],v[mid++]);
            }
            else{
                swap(v[mid],v[r--]);
            }
        }
        
    }
};