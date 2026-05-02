class Solution {
public:
    bool dfs(int node, int currColor, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = currColor;

        for (int nei : graph[node]) {
           
            if (color[nei] == 0) {
                if (dfs(nei, -currColor, graph, color) == false) {
                    return false;
                }
            } 
            else if (color[nei] == currColor) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
       
        vector<int> color(m, 0);

        for (int i = 0; i < m; i++) {
            if (color[i] == 0) {
                if (dfs(i, 1, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};