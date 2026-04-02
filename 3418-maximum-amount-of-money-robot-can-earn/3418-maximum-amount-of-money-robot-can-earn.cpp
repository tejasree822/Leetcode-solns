class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] -> max coins at (i, j) with k neutralizations remaining
        // Initialize with a very small number to represent unvisited/impossible states
        long long INF = 1e16; 
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        // Base case: Starting point (0, 0)
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = coins[0][0];
            dp[0][0][2] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; // Paid the robber
            dp[0][0][1] = 0;           // Neutralized (1 use left from 2 total)
            dp[0][0][2] = 0;           // Neutralized (effectively same as 1 here)
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; ++k) {
                    long long prev_max = -INF;
                    
                    // Come from Top
                    if (i > 0) prev_max = max(prev_max, dp[i-1][j][k]);
                    // Come from Left
                    if (j > 0) prev_max = max(prev_max, dp[i][j-1][k]);

                    if (prev_max == -INF) continue;

                    if (coins[i][j] >= 0) {
                        // Gain coins, k doesn't change
                        dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);
                    } else {
                        // Option 1: Don't neutralize (pay the robber)
                        dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);
                        
                        // Option 2: Neutralize (if k > 0)
                        if (k > 0) {
                            long long prev_k_minus_1 = -INF;
                            if (i > 0) prev_k_minus_1 = max(prev_k_minus_1, dp[i-1][j][k-1]);
                            if (j > 0) prev_k_minus_1 = max(prev_k_minus_1, dp[i][j-1][k-1]);
                            
                            dp[i][j][k] = max(dp[i][j][k], prev_k_minus_1);
                        }
                    }
                }
            }
        }

        return (int)dp[m-1][n-1][2];
    }
};