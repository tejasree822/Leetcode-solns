class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };
    string s;
    Node dp[11][2][2][3][11][11];
    bool vis[11][2][2][3][11][11];
    Node dfs(int pos, int tight, int started,
             int len, int prev2, int prev1) {
        if (pos == s.size()) {
            return {1, 0};
        }
        if (vis[pos][tight][started][len][prev2][prev1])
            return dp[pos][tight][started][len][prev2][prev1];

        vis[pos][tight][started][len][prev2][prev1] = true;
        Node res = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, ntight, 0, 0, 10, 10);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                if (!started) {
                    Node nxt = dfs(pos + 1, ntight, 1, 1, 10, d);

                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
                else if (len == 1) {
                    Node nxt = dfs(pos + 1, ntight, 1, 2, prev1, d);

                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
                else {
                    int add =
                        ((prev1 > prev2 && prev1 > d) ||
                         (prev1 < prev2 && prev1 < d));

                    Node nxt = dfs(pos + 1, ntight, 1, 2, prev1, d);

                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav + 1LL * add * nxt.cnt;
                }
            }
        }

        return dp[pos][tight][started][len][prev2][prev1] = res;
    }

    long long calc(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 0, 10, 10).wav;
    }

    int totalWaviness(int num1, int num2) {
        return (int)(calc(num2) - calc(num1 - 1));
    }
};