class Solution {
public: 
bool bfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& color){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        color[node]=1;
        while(!q.empty()){
            int nodeq=q.front();
            
            q.pop();
            for(auto it:graph[nodeq]){
                 if(!vis[it]){
                    vis[it]=1;
                    if(color[nodeq]==1){
                        color[it]=0;
                    }
                    else{
                        color[it]=1;
                    }
                    q.push(it);
                 }
                 else{
                    if(color[nodeq]==color[it]) return false;
                 }
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> vis(m,0);
        queue<int> q;
        vector<int>color(m,0);
        
        for(int i=0;i<m;i++){
            if(!vis[i]){
                if(!bfs(i,graph,vis,color))
                {return false;
                }
            }
        }
        return true;
    }
};