class Solution {
public:
    int longestPalindrome(vector<string>& v) {
        map<string,int>mp;
        int n=v.size();
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        int ans=0;
        bool b=false;
        for(int i=0;i<n;i++){
            // interesting stuff
            // writing string s=v[i][0] gives error but writing the way abhi likha doesnt
            string s;
            s=v[i][1];
            s+=v[i][0];
            if(mp[s]>0 and mp[v[i]]>0){
                // F dont miss this mp[v[i]]>0 condition costs you 12 mins more
                if(s==v[i]){
                    if(mp[s]&1){
                        //if odd occurances are there can add it in the middle
                        b=true;
                    }
                    int c=mp[s]&1?mp[s]-1:mp[s];
                    ans+=2*(c);
                    mp[s]=0;
                    continue;
                }
                ans+=4;
                mp[s]--;
                mp[v[i]]--;
            }
        }
        ans+=b?2:0;
        return ans;

    }
};