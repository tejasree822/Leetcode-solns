class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int a=nums[0];
        int b=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<a){
                a=nums[i];
            }
            if(nums[i]>b){
                b=nums[i];
            }
        }
       vector<int> ans;
       unordered_set<int> mp;
       for(int x:nums){
        mp.insert(x);
       }
       int k=a+1;
       while(k!=b){
        if(mp.find(k)==mp.end()){
            ans.push_back(k);
        }
        k++;
       }
       return ans;
    }
};