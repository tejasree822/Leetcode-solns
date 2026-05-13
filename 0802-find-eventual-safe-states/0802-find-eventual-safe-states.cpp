class Solution {
public:
bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathVis,vector<int>& check){
    int m=graph.size();
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:graph[node]){
        if(!vis[it]){
        if(dfs(it,graph,vis,pathVis,check))
        {return true;
        }

        }
        else if(pathVis[it]) {return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;



    
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> vis(m,0);
vector<int> pathVis(m,0);
vector<int> check(m,0);
        vector<int>safe;
        for(int i=0;i<m;i++){
            if(!vis[i]){
                (dfs(i,graph,vis,pathVis,check));
            }
        }
        for(int i=0;i<m;i++){
            if(check[i]==1) safe.push_back(i);
        }
        return safe;
    }
};