class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const long mod = 1e9 + 7;

        vector<vector<long long>> maxProd(m, vector<long long>(n));
        vector<vector<long long>> minProd(m, vector<long long>(n));

        maxProd[0][0] = minProd[0][0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            maxProd[0][j] = minProd[0][j] = maxProd[0][j-1] * grid[0][j];
        }

        // first column
        for (int i = 1; i < m; i++) {
            maxProd[i][0] = minProd[i][0] = maxProd[i-1][0] * grid[i][0];
        }

        // fill DP
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];

                long long a = val * maxProd[i-1][j];
                long long b = val * minProd[i-1][j];
                long long c = val * maxProd[i][j-1];
                long long d = val * minProd[i][j-1];

                maxProd[i][j] = max({a, b, c, d});
                minProd[i][j] = min({a, b, c, d});
            }
        }

        long long ans = maxProd[m-1][n-1];

        if (ans < 0) return -1;

        return ans % mod;
    }
};