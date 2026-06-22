class Solution {
public:
     int f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp,int offset){
        if(target<-offset||target>offset)
            return 0;
       if(ind==0){
        int cnt=0;
        if(target==nums[0]){
            cnt++;
        }
            if(target==(-nums[0])){
               cnt++;
            } 
        return cnt;
       }
      if(dp[ind][target+offset]!=-1) return dp[ind][target+offset];
        int plus=f(ind-1,target-nums[ind],nums,dp,offset);
        int minus=f(ind-1,target+nums[ind],nums,dp,offset);
        return dp[ind][target+offset]=plus+minus;
     }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       int sum=0;
       for(int num:nums){
        sum+=num;
       }
       vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
       
        return f(n-1,target,nums,dp,sum);
    }
};