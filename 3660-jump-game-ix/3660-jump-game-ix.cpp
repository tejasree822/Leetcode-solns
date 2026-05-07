class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> pref_max(n);
        pref_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref_max[i] = max(pref_max[i - 1], nums[i]);
        }
        vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff_min[i] = min(suff_min[i + 1], nums[i]);
        }
        vector<int> ans(n);
        int last_split = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (i == n - 1 || pref_max[i] <= suff_min[i + 1]) {
                int current_chunk_max = pref_max[i];
                for (int j = last_split; j <= i; j++) {
                    ans[j] = current_chunk_max;
                }
                last_split = i + 1;
            }
        }
        
        return ans;
    }
};