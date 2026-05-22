class Solution {
public: 
bool bfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& color){
        queue<pair<int,int>> q;
        q.push({node,1});
        vis[node]=1;
        color[node]=1;
        while(!q.empty()){
            int nodeq=q.front().first;
            int colo=q.front().second;
            q.pop();
            for(auto it:graph[nodeq]){
                 if(!vis[it]){
                    vis[it]=1;
                    if(colo==1){
                        color[it]=0;
                    }
                    else{
                        color[it]=1;
                    }
                    q.push({it,color[it]});
                 }
                 else{
                    if(colo==color[it]) return false;
                 }
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> vis(m,0);
        queue<pair<int,int>> q;
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