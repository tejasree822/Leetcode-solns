class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n=nums.size();
        long long sum_elements = 0;
        long long current_f = 0;
        for (int i = 0; i < n; i++) {
            sum_elements += nums[i];
            current_f += (long long)i * nums[i];
        }
        long long max_f = current_f;
        for (int k = 1; k < n; k++) {
            current_f+=sum_elements - n * nums[n - k];
            max_f = max(max_f, current_f);
        }

        return (int)max_f;
    }
};