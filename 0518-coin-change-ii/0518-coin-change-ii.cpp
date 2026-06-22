class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
       vector<unsigned long long>prev(amount+1,0),curr(amount+1,0);
        for (int T = 0; T <= amount; T++) {
            prev[T] = (T % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int T = 0; T <= amount; T++) {

                unsigned long long nottake = prev[T];

                unsigned long long take = 0;

                if (coins[ind] <= T) {
                    take = curr[T - coins[ind]];
                }

                curr[T] = take + nottake;
            }
            prev=curr;
        }

        return (int)prev[amount];
    }
};