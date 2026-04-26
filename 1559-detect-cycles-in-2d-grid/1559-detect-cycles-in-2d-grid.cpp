class Solution {
public:
bool solve(int r, int c, int pR, int pC, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    int m = grid.size();
    int n = grid[0].size();
    vis[r][c] = true;

    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nRow = r + dRow[i];
        int nCol = c + dCol[i];
        if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == grid[r][c]) {
            if (vis[nRow][nCol]) {
                if (nRow != pR || nCol != pC) return true;
            } else {
                if (solve(nRow, nCol, r, c, grid, vis)) return true;
            }
        }
    }
    return false; 
}
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       vector<vector<bool>> vis(m, vector<bool>(n, false));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                if(solve(i,j,-1,-1,grid,vis)) return true;
            }
        }
       }
       return false;
    }
};