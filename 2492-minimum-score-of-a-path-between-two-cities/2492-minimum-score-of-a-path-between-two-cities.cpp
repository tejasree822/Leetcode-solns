class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: roads){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
        }
        
        int mini=1e9;
        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(const auto &it:adj[node]){
                 int v=it.first;
        int dis=it.second;
      mini=min(mini,dis);
     if(!visited[v]){
        visited[v]=true;
        q.push(v);
     }
            }

        }
    
        
        return mini;
    }
};