class Solution {
public:
    int partitionString(string s) {
        //dp ka sawal hai
        // for every string piche wali check ki whether the size of string is same as length 
        int n=s.size(),startingPos=0;
        set<char>st;
        int ans=0;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            // check the length of substring formed
            // length of the substring formed=i-startingPos +1
            int len=i-startingPos+1;
            if(len>st.size()){
                startingPos=i;
                ans++;
                st.clear();
                st.insert(s[i]);
            }
            // cout<<i<<" "<<ans<<endl;
        }
        // if(startingPos==n-1){
            ans++;
        // }
        return ans;
    }
};