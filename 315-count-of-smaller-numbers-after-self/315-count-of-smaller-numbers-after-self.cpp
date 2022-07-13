struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    int lc;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
        lc=0;
    }
};
class Solution {
public:
    int insert(struct Node* node, int key){
        struct Node* r=NULL,*p;
        int c=0;
        while(node){
            r=node;
            if(node->val>=key){
                node->lc++;
                node=node->left;
            }
            else{
                c+=1+node->lc;
                node=node->right;
            }
        }
        p=new Node(key);
        if(r->val>=key){
            r->left=p;
        }
        else{
            r->right=p;
        }
        return c;        
    }
    vector<int> countSmaller(vector<int>& v) {
        int n=v.size();        
        vector<int>ans(n,0);
        vector<int>c=v;
        sort(c.begin(),c.end());
        bool b=false;
        for(int i=0;i<n;i++){
            if(c[i]!=v[i]){
                b=true;
                break;
            }
        }
        if(!b){
            return ans;
        }
        sort(c.begin(),c.end(),greater<int>());
        for(int i=0;i<n;i++){
            if(c[i]!=v[i]){
                b=false;
                break;
            }
        }
        cout<<b<<endl;
        if(b){
            int cnt=0;
            ans[n-1]=0;
            int j=n-2;
            while(j>-1 && v[j]>=v[j+1]){
                if(v[j]>v[j+1])
                ans[j]=n-j-1;
                if(v[j]==v[j+1]) ans[j]=ans[j+1];
                j--;
        }
            return ans;
        }
        
        struct Node* root=new Node(v[n-1]);
        for(int i=n-2;i>=0;i--){
            ans[i]=insert(root,v[i]);
        }
        return ans;
    }
};