class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int mod = 12345;

        int size = m * n;
        vector<int> res(size);

        // Step 1: prefix
        long long pre = 1;
        for(int i = 0; i < size; i++) {
            res[i] = pre;
            pre = (pre * grid[i / n][i % n]) % mod;
        }

        // Step 2: suffix
        long long suf = 1;
        for(int i = size - 1; i >= 0; i--) {
            res[i] = (res[i] * suf) % mod;
            suf = (suf * grid[i / n][i % n]) % mod;
        }

        // Step 3: put back into grid
        for(int i = 0; i < size; i++) {
            grid[i / n][i % n] = res[i];
        }

        return grid;
    }
};