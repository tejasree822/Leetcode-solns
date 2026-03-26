class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int val : row) totalSum += val;
        }

        // 1. Horizontal Cuts
        unordered_map<int, int> topFreq, bottomFreq;
        for (const auto& row : grid) {
            for (int val : row) bottomFreq[val]++;
        }

        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) { // Cut after row i
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                topFreq[val]++;
                if (--bottomFreq[val] == 0) bottomFreq.erase(val);
                topSum += val;
            }
            long long bottomSum = totalSum - topSum;

            // Check if we can equalize by discounting from top OR bottom
            if (checkSection(topSum, bottomSum, topFreq, i + 1, n, grid, 0, i, 0, n - 1) ||
                checkSection(bottomSum, topSum, bottomFreq, m - 1 - i, n, grid, i + 1, m - 1, 0, n - 1)) {
                return true;
            }
        }

        // 2. Vertical Cuts
        unordered_map<int, int> leftFreq, rightFreq;
        for (const auto& row : grid) {
            for (int val : row) rightFreq[val]++;
        }

        long long leftSum = 0;
        for (int j = 0; j < n - 1; ++j) { // Cut after col j
            for (int i = 0; i < m; ++i) {
                int val = grid[i][j];
                leftFreq[val]++;
                if (--rightFreq[val] == 0) rightFreq.erase(val);
                leftSum += val;
            }
            long long rightSum = totalSum - leftSum;

            if (checkSection(leftSum, rightSum, leftFreq, m, j + 1, grid, 0, m - 1, 0, j) ||
                checkSection(rightSum, leftSum, rightFreq, m, n - 1 - j, grid, 0, m - 1, j + 1, n - 1)) {
                return true;
            }
        }

        return false;
    }

private:
    
        bool checkSection(long long sLarge, long long sSmall, unordered_map<int, int>& freq, 
                  int h, int w, const vector<vector<int>>& grid, 
                  int r1, int r2, int c1, int c2) {
    
    // 1. If already equal, no discount needed
    if (sLarge == sSmall) return true;

    // 2. The difference must be positive 
    long long diff = sLarge - sSmall;
    if (diff <= 0) return false;

    // 3. CRITICAL: Only check the map if diff fits in an int.
    // Also, if diff > total grid values' potential max, it's impossible.
    if (diff > 2147483647LL) return false; 
    
    int target = (int)diff;
    if (freq.find(target) == freq.end()) return false;

    // 4. Connectivity Check (This part of your logic was likely correct)
    if (h > 1 && w > 1) return true; // Bulk rectangle is always connected
    if (h == 1) return (grid[r1][c1] == target || grid[r1][c2] == target);
    if (w == 1) return (grid[r1][c1] == target || grid[r2][c1] == target);

    return false;
}
    
};