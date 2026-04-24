class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
       int count[1001] = {0}; // Fixed range O(1) space relative to N
    int n = nums.size();
    
    for (const auto& row : nums) {
        // Use a boolean array to handle duplicates within a single row
        bool seenInRow[1001] = {false};
        for (int x : row) {
            if (!seenInRow[x]) {
                count[x]++;
                seenInRow[x] = true;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i <= 1000; i++) { // Linear scan of the range
        if (count[i] == n) {
            result.push_back(i);
        }
    }
    return result; // Already sorted!
    }
};