class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        unordered_map<int, vector<int>> groups;

       
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        // Step 2: For each group, use prefix sums to find the total distance
        for (auto& entry : groups) {
            vector<int>& indices = entry.second;
            int k = indices.size();
            if (k <= 1) continue; // No other 'j' exists

            // Calculate total sum of all indices in this group first
            long long total_sum = 0;
            for (int idx : indices) total_sum += idx;

            long long left_sum = 0;
            for (int i = 0; i < k; i++) {
                long long current_index = indices[i];
                
                // Sum of distances to the right:
                // (Sum of all indices to the right) - (count of elements to the right * current_index)
                long long right_sum = total_sum - left_sum - current_index;
                int right_count = k - 1 - i;
                int left_count = i;

                long long total_dist = 0;
                
                // Left contribution: (i * current_index) - sum_of_indices_to_left
                total_dist += (1LL * left_count * current_index) - left_sum;
                
                // Right contribution: sum_of_indices_to_right - (right_count * current_index)
                total_dist += right_sum - (1LL * right_count * current_index);

                arr[current_index] = total_dist;

                // Update left_sum for the next element in the group
                left_sum += current_index;
            }
        }

        return arr;
    }
};