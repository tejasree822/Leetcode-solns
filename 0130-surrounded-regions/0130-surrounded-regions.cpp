class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<char>>& board) {
      
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#';

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], m, n, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, m, n, board);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, m, n, board);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, m, n, board);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, m, n, board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; 
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; 
                }
            }
        }
    }
};