class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
        int n=nums.size(); 
        int tot=1<<n;
       for (int num=0;num<tot;num++) {
            vector<int> sub;
           for (int i=0;i<n;i++) {
              if ((num&(1<<i))!=0) {
                    sub.push_back(nums[i]);
                }
            }
            
            result.push_back(sub); 
        }
        
        return result;
    }
};