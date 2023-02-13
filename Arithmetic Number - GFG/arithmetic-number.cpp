//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int An, int d){
        // An=a+(n-1)*d;
        if(d==0){
            return A==An;
        }
        if(An>A and d<=0){
            return 0;
        }
        if(An<A and d>=0){
            return 0;
        }
        return (An-A)%d==0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends