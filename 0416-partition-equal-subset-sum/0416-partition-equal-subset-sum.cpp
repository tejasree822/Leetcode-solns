class Solution {
    public:

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=(sum*0.5);
       vector<bool> prev(target+1,false);
       vector<bool> curr(target+1,false);
        if((sum%2)!=0){
            return false;
        }
        
       
        else{ 
             prev[0]=true;
            
             if(nums[0] <= target) 
               { prev[nums[0]]=true;}
                for(int i=1;i<n;i++){
                    for(int j=1;j<=target;j++){
                        bool notpick=prev[j];
                     bool pick=false;
                      if(j>=nums[i]){
                         pick=prev[j-nums[i]];
                          }
                          curr[j]=pick||notpick;
                    }
                    prev=curr;
                }
             

        }
        return prev[target];
        
    }
};