class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<unsigned long long>> dp(
            n,
            vector<unsigned long long>(amount + 1, 0)
        );

        for (int T = 0; T <= amount; T++) {
            dp[0][T] = (T % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int T = 0; T <= amount; T++) {

                unsigned long long nottake = dp[ind - 1][T];

                unsigned long long take = 0;

                if (coins[ind] <= T) {
                    take = dp[ind][T - coins[ind]];
                }

                dp[ind][T] = take + nottake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};