class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
         int totalSum=0;
         for (int x:nums)
            totalSum+=x;
            if(abs(target)>totalSum)
            return 0;
        if((totalSum+target)%2!=0)
            return 0;
             int req=(totalSum+target)/2;
         vector<vector<int>> dp(n,vector<int>(req+1,0));
         if (nums[0]==0)
            dp[0][0]=2;
        else {
            dp[0][0]=1;

            if (nums[0]<=req)
                dp[0][nums[0]]=1;
        }

        for (int ind = 1; ind < n; ind++) {

            for (int sum = 0; sum <= req; sum++) {

                int notTake = dp[ind - 1][sum];

                int take = 0;
                if (nums[ind] <= sum)
                    take = dp[ind - 1][sum - nums[ind]];

                dp[ind][sum] = take + notTake;
            }
        }

        return dp[n - 1][req];
    }
};