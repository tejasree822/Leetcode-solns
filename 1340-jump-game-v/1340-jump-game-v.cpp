class Solution {
private:
    int dp[1001];
    
    int dfs(int i, const vector<int>& arr, int d, int n) {
        if (dp[i] != 0) return dp[i];
        
        int max_jumps = 1;
        
        for (int x = 1; x <= d && i + x < n; ++x) {
            if (arr[i + x] >= arr[i]) break;
            max_jumps = max(max_jumps, 1 + dfs(i + x, arr, d, n));
        }
        
        for (int x = 1; x <= d && i - x >= 0; ++x) {
            if (arr[i - x] >= arr[i]) break;
            max_jumps = max(max_jumps, 1 + dfs(i - x, arr, d, n));
        }
        
        return dp[i] = max_jumps;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i, arr, d, n));
        }
        
        return ans;
    }
};