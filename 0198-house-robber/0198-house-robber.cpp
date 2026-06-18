class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
      int previ=nums[0];
      int prev2i=0;


        for(int i=1;i<n;i++){
            
            int take=nums[i];
            if(i>1) take+=prev2i;
           
            int nottake=previ;
            int curri=max(take,nottake);
            prev2i=previ;
            previ=curri;
            
        }
        return previ;

     }
};