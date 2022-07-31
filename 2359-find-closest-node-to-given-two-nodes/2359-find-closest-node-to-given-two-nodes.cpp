class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2){
            return node1;
        }
        int n=edges.size();
        vector<int>dist1(n,-1);
        vector<int>dist2(n,-1);
        queue<int>q;
        q.push(node1);
        dist1[node1]=0;
        vector<bool>visited(n,false);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            visited[t]=1;
            int adj=edges[t];
            if(adj!=-1 and visited[adj]==false){
                dist1[adj]=1+dist1[t];
                q.push(adj);
            }
        }
        q.push(node2);
        dist2[node2]=0;
        for(int i=0;i<n;i++)visited[i]=false;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            visited[t]=1;
            
            int adj=edges[t];
            if(adj!=-1 and visited[adj]==false){
                dist2[adj]=1+dist2[t];
                q.push(adj);
            }
        }
        int ans=-1;
        int maxDist=0;
        int gloDist=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(dist1[i]!= -1 and dist2[i]!=-1){
                maxDist=max(dist1[i],dist2[i]);
                if(maxDist<gloDist){
                    gloDist=maxDist;
                    ans=i;
                }
            }
        }
        return ans;
    }
};