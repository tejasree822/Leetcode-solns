class Solution {
public:
     int f(int ind,int target,vector<int>& nums){
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
      
        int plus=f(ind-1,target-nums[ind],nums);
        int minus=f(ind-1,target+nums[ind],nums);
        return plus+minus;
     }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       
        return f(n-1,target,nums);
    }
};