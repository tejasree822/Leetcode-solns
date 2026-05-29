class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            while(nums[i]!=0){
                sum+=nums[i]%10;
              nums[i]/=10;
              
            }
            nums[i]=sum;

        }
        int min=INT_MAX;
        for(int i=0;i<n;i++){
        if(nums[i]<min){
            min=nums[i];
        }
        }
        return min;
    }
};