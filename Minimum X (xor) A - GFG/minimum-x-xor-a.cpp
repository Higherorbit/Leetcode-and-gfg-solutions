//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int s=__builtin_popcount(b);
        int sa=__builtin_popcount(a);
        if(s==sa){
            return a;
        }
        // 0111
        // 1100
        else if(s>sa){
            int dif=s-sa;
            int ans=0;
            for(int i=0;i<=63;i++){
                int k=(a>>i)&1;
                // cout<<"i "<<i<<" (a>>i)&1"<<k<<endl;
                if(k==0){
                    // cout<<"i "<<i<<endl;
                    ans+=1<<i;
                    dif--;
                    // cout<<dif<<endl;
                    // cout<<ans<<endl;
                    if(dif==0){
                        // cout<<"WHAT";
                        // cout<<a<<endl;
                        return a+ans;
                    }
                }
            }
        }
        else{
            int dif=s;
            int ans=0;
            for(int i=63;i>=0;i--){
                if(a>>i&1){
                    ans+=1<<i;
                    dif--;
                }
                if(dif==0){
                    return ans;
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends