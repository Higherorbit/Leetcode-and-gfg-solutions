/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &v) {
        int n=v.length();
        int l=0;
        int r=n-1;
        int mi=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid==n-1){
                r=mid-1;
            }
            else if(mid==0){
                l=mid+1;
            }
            else{
                if(v.get(mid)>=v.get(mid+1) and v.get(mid)>=v.get(mid-1)){
                    mi=mid;
                    break;
                }
                else if(v.get(mid)<=v.get(mid+1)){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        
        int l1,r1,l2,r2;
        if(v.get(mi)<target){
            return -1;
        }
        else if(v.get(mi)>target){
            l1=0;
            r1=mi;
        }
        else{
            l2=mi;
            r2=n-1;
        }
        while(l1<=r1){
            int mid=l1+(r1-l1)/2;
            if(v.get(mid)==target){
                return mid;
            }
            else if(v.get(mid)>target){
                r1=mid-1;
            }
            else{
                l1=mid+1;
            }
        }
        while(l2<=r2){
            int mid=l2+(r2-l2)/2;
            if(v.get(mid)==target){
                return mid;
            }
            else if(v.get(mid)>target){
                l2=mid+1;
            }
            else{
                r2=mid-1;
            }
        }
        return -1;        
    }
};