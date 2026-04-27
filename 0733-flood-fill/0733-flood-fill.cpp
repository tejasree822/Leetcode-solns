class Solution {
public:
    bool isValid(int r, int c, int totalRows, int totalCols, vector<vector<int>>& grid,vector<vector<bool>>& visited) {
    if (r < 0 || r >= totalRows) return false;
    if (c < 0 || c >= totalCols) return false;
    if (visited[r][c] == true) return false; 
    
    return true;
 }
   void solve(int r,int c,vector<vector<int>>& image,vector<vector<bool>>& visited,int sr,int sc,int color,    int    k) {
   int m=image.size();
   int n=image[0].size();
   int dr[] = {1, -1, 0, 0};

   int dc[] = {0, 0, 1, -1};
visited[r][c] = true;
   if (image[r][c] == k) {
    image[r][c] = color;
    for (int i = 0; i < 4; i++) {
        int nextRow = r + dr[i];
        int nextCol = c + dc[i];
        if (isValid(nextRow, nextCol, m, n, image, visited))
            solve(nextRow, nextCol, image, visited, r, c, color, k);
    }
}
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int k=image[sr][sc];
      vector<vector<bool>> visited(m, vector<bool>(n, false));
        solve(sr,sc,image,visited,sr,sc,color,k);
        return image;

    }
};