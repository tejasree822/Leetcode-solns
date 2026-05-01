class Solution {
public:
  void dfs(int s, int n, vector<vector<int>>& isConnected, vector<bool>& visited) {
    visited[s] = true;
    for (int i = 0; i < n; i++) {
        if (isConnected[s][i] == 1 && !visited[i] ) {
            dfs(i, n, isConnected, visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
int province=0;
vector<bool> visited(n,false);
for(int i=0;i<n;i++){
    if(!visited[i]){
        dfs(i,n,isConnected,visited);
        province++;
    }
    
}
return province;




    }
};