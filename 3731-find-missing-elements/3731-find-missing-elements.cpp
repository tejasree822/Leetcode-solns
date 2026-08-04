class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<int> ans;
       unordered_set<int> mp;
       for(int x:nums){
        mp.insert(x);
       }
       int a=nums[0];
       int b=nums[nums.size()-1];
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