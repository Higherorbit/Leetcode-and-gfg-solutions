class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        string a=s.substr(0,n/2);
        string b=s.substr(n/2,n/2);
        set<char>vow;
        vow.insert('a'); 
        vow.insert('e');
        vow.insert('i');
        vow.insert('o');
        vow.insert('u');
        vow.insert('U');
        vow.insert('O');
        vow.insert('I');
        vow.insert('E');
        vow.insert('A');
        
        int cnt1=0,cnt2=0;
        for(auto &i:a){
            if(vow.count(i))
                cnt1++;
        }
        for(auto &i:b){
            if(vow.count(i)){
                cnt2++;
            }
        }
        return (cnt1==cnt2);
    }
};