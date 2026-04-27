class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // 0=Left, 1=Right, 2=Up, 3=Down
        int dr[] = {0,  0, -1,  1};
        int dc[] = {-1, 1,  0,  0};  // ✅ fixed

        vector<vector<int>> exits = {
            {},
            {0, 1},  // street 1: Left, Right
            {2, 3},  // street 2: Up, Down
            {0, 3},  // street 3: Left, Down
            {1, 3},  // street 4: Right, Down
            {0, 2},  // street 5: Left, Up
            {1, 2}   // street 6: Right, Up
        };

        int opposite[] = {1, 0, 3, 2};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            if (r == m-1 && c == n-1) return true;

            for (int dir : exits[grid[r][c]]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;

                int needed = opposite[dir];
                bool canEnter = false;
                for (int d : exits[grid[nr][nc]]) {
                    if (d == needed) { canEnter = true; break; }
                }

                if (canEnter) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};