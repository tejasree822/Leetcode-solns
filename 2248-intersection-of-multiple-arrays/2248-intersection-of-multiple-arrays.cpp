class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            
            unordered_set<int> uniqueInRow(nums[i].begin(), nums[i].end());
            
            for (int x : uniqueInRow) {
                counts[x]++;
            }
        }

        vector<int> result;
        for (auto const& [val, freq] : counts) {
            
            if (freq == n) {
                result.push_back(val);
            }
        }

        // Sort only once at the very end
        sort(result.begin(), result.end());
        return result;
    }
};