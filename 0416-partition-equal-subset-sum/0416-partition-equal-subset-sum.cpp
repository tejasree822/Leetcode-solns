class Solution {
public:
bool f(int i,int target,int n,vector<int>& nums,vector<vector<int>>& dp){
    if(target==0) return true;
    if(i==0){
        return nums[0]==target;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    bool notpick=f(i-1,target,n,nums,dp);
    bool pick=false;
    if(target>=nums[i]){
       pick=f(i-1,target-nums[i],n,nums,dp);
    }
    return dp[i][target]=pick||notpick;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>((sum*0.5)+1,-1));
        if(sum%2!=0){
            return false;
        }
        else{
             return f(n-1,(sum*0.5),n,nums,dp);
        }
        return 0;
        
    }
};