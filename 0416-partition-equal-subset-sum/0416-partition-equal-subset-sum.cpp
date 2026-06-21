class Solution {
    public:

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=(sum*0.5);
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        if((sum%2)!=0){
            return false;
        }
        else{
             for(int i=0;i<n;i++){
                dp[i][0]=true;
             }
             if(nums[0] <= target) 
               { dp[0][nums[0]]=true;}
                for(int i=1;i<n;i++){
                    for(int j=1;j<=target;j++){
                        bool notpick=dp[i-1][j];
                     bool pick=false;
                      if(j>=nums[i]){
                         pick=dp[i-1][j-nums[i]];
                          }
                          dp[i][j]=pick||notpick;
                    }
                }
             

        }
        return dp[n-1][target];
        
    }
};