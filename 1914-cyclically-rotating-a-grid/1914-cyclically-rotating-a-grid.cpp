class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
      
        int layers = min(m, n) / 2;
        
        for (int layer = 0; layer < layers; layer++) {
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;
            
            vector<int> current_layer;
            
            for (int i = left; i <= right; i++) current_layer.push_back(grid[top][i]);
          
            for (int i = top + 1; i <= bottom; i++) current_layer.push_back(grid[i][right]);
           
            for (int i = right - 1; i >= left; i--) current_layer.push_back(grid[bottom][i]);
            
            for (int i = bottom - 1; i > top; i--) current_layer.push_back(grid[i][left]);
            
            int len = current_layer.size();
            int shift = k % len; 
            int idx = 0;
            
            for (int i = left; i <= right; i++) {
                grid[top][i] = current_layer[(shift + idx++) % len];
            }
            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = current_layer[(shift + idx++) % len];
            }
            for (int i = right - 1; i >= left; i--) {
                grid[bottom][i] = current_layer[(shift + idx++) % len];
            }
            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = current_layer[(shift + idx++) % len];
            }
        }
        
        return grid;
    }
};