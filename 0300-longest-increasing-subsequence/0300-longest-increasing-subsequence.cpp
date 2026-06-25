class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=dp[0];
        for(int ind =1;ind<=n-1;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[prev]<nums[ind]){
                    dp[ind]=max(dp[ind],dp[prev]+1);
                }
                maxi=max(maxi,dp[ind]);
            }
        }
        return maxi;
    }
};