class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        parent[x]=find(parent[x]);
        return parent[x];
    }
    bool equationsPossible(vector<string>& v) {
        for(int i=0;i<26;i++){
            parent.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            if(v[i][1]=='='){
                int x=find(v[i][0]-'a');
                int y=find(v[i][3]-'a');
                if(x!=y){
                    parent[y]=x;
                }
            }
            else{
                int x=find(v[i][0]-'a');
                int y=find(v[i][3]-'a');
                if(x==y){
                    return false;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i][1]=='='){
                int x=find(v[i][0]-'a');
                int y=find(v[i][3]-'a');
                if(x!=y){
                    parent[y]=x;
                }
            }
            else{
                int x=find(v[i][0]-'a');
                int y=find(v[i][3]-'a');
                if(x==y){
                    return false;
                }
            }
        }
        return true;
        
        
    }
};