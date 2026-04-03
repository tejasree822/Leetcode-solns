class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
          int n = robots.size();
        
        // 1. Prepare and Sort Data
        vector<pair<int, int>> r_data(n);
        for (int i = 0; i < n; ++i) {
            r_data[i] = {robots[i], distance[i]};
        }
        sort(r_data.begin(), r_data.end());
        sort(walls.begin(), walls.end());

        // dp[i][0]: Max walls destroyed using first i robots, i-th robot fired LEFT or NONE
        // dp[i][1]: Max walls destroyed using first i robots, i-th robot fired RIGHT
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = 0; i < n; ++i) {
            long long pos = r_data[i].first;
            long long d = r_data[i].second;

            // --- Case A: Robot i fires LEFT ---
            // Bullet is blocked by the robot at i-1
            long long left_barrier = (i == 0) ? -2e9 : r_data[i-1].first;
            long long reach_l = max(left_barrier + 1, pos - d);
            
            auto it_start_l = lower_bound(walls.begin(), walls.end(), (int)reach_l);
            auto it_end_l = upper_bound(walls.begin(), walls.end(), (int)pos);
            int count_l = std::distance(it_start_l, it_end_l);

            // Special check: Overlap with robot i-1 if it fired RIGHT
            int overlap = 0;
            if (i > 0) {
                long long prev_pos = r_data[i-1].first;
                long long prev_d = r_data[i-1].second;
                // Robot i-1's right fire is blocked by robot i
                long long prev_reach_r = min(pos - 1, prev_pos + prev_d);
                
                long long over_start = max(reach_l, prev_pos);
                long long over_end = min(pos, prev_reach_r);
                
                if (over_start <= over_end) {
                    auto o_start = lower_bound(walls.begin(), walls.end(), (int)over_start);
                    auto o_end = upper_bound(walls.begin(), walls.end(), (int)over_end);
                    overlap = std::distance(o_start, o_end);
                }
            }

            // Update dp[i+1][0]: Max of firing left now vs firing none
            int fire_left = max(dp[i][0] + count_l, dp[i][1] + count_l - overlap);
            int fire_none = max(dp[i][0], dp[i][1]);
            dp[i+1][0] = max(fire_left, fire_none);

            // --- Case B: Robot i fires RIGHT ---
            // Bullet is blocked by the robot at i+1
            long long right_barrier = (i == n - 1) ? 2e9 : r_data[i+1].first;
            long long reach_r = min(right_barrier - 1, pos + d);
            
            auto it_start_r = lower_bound(walls.begin(), walls.end(), (int)pos);
            auto it_end_r = upper_bound(walls.begin(), walls.end(), (int)reach_r);
            int count_r = std::distance(it_start_r, it_end_r);

            // If robot i fires right, it doesn't matter what i-1 did because 
            // robot i blocks any bullet from the left anyway.
            dp[i+1][1] = max(dp[i][0] + count_r, dp[i][1] + count_r);
        }

        return max(dp[n][0], dp[n][1]);
    }
};