class Solution {
public:
    int search(vector<int>& a, int key) {
        int n=a.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            // we need to check on which line it is
            if(a[mid]==key){
                return mid;
            }
            // for 1st line
            if(a[s]<=a[mid]){
                if(a[s]<=key and key<=a[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            // for 2nd line
            else{
                if(a[mid]<=key and key<=a[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};