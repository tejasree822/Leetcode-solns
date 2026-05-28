class Solution {
public:
void solve(int index,vector<int>& current,vector<vector<int>>& result,vector<int>& nums){
    if(index==nums.size()){
        if(find(result.begin(),result.end(),current)==result.end()){

        result.push_back(current);
       
        }
         return;
    }
    current.push_back(nums[index]);
    solve(index+1,current,result,nums);
    current.pop_back();

    solve(index+1,current,result,nums);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> current;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        solve(0,current,result,nums);
        return result;
    }
};