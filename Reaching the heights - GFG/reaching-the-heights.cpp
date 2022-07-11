// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    vector<int>v;
    if(n==1){
        return {a[0]};
    }
    int sum=0;
    sort(a,a+n);
    int s1=0;
    int s2=0;
    // if(n%2==1){
        for(int i=0;i<=n/2-1;i++){
            s1+=a[i];
        }
        for(int i=n/2;i<n;i++){
            s2+=a[i];
        }
    // }
    // else{
    //     for(int i=0;i<=n/2;i++){
    //         s1+=a[i];
    //     }
    //     for(int i=n/2+1;i<n;i++){
    //         s2+=a[i];
    //     }
    // }
    if(s1>=s2){
        return {-1};
    }
    int i=n-1;
    int j=0;
    while(i>=j){
        v.push_back(a[i]);
        i--;
        if(i<j) break;
        v.push_back(a[j]);
        j++;
    }
    return v;
}
