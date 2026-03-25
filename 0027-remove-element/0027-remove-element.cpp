class Solution {
public:
    int removeElement(vector<int>& nums, int value) {
        int n=nums.size();
        int left,right;
         vector<int> nums1;
         for(int i=0;i<n;i++){
            if(nums[i]!=value){
                nums1.push_back(nums[i]);
            }
         }
         int l=nums1.size();
        for(int i=0;i<nums1.size();i++){
            nums[i]=nums1[i];
        }
         return l;
        }
    
};