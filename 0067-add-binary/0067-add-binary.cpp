#define sz(x) static_cast<int>(x.size())
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int sza=a.size();
        int szb=b.size();
        if(sza>szb){
            for(int i=0;i<sza-szb;i++){
                b="0"+b;
            }
        }
        else if(sza<szb){
            for(int i=0;i<szb-sza;i++){
                a="0"+a;
            }
        }
        int n=a.size();
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='1' and b[i]=='1'){
                if(c==0){
                ans+="0";
                }
                else{
                    ans+="1";
                }
                c=1;
            }
            else if(a[i]=='1' or b[i]=='1'){
                if(c==0){
                ans+="1";
                    c=0;
                }
                else{
                    ans+="0";
                    c=1;
                }                
            }
            else{
                if(c==0){
                ans+="0";
                    c=0;
                }
                else{
                    ans+="1";
                    c=0;
                } 
            }
        }
        if(c==1){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }       
};