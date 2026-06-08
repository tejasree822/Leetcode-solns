class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        queue<int> q1;
        queue<int> q2;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                q1.push(nums[i]);
               
            }
            else if(nums[i]>pivot){
                q2.push(nums[i]);
                
            }
            else{
         count++;
        
            }
        }
        nums.clear();
        while(!q1.empty()){
           int node = q1.front();
           q1.pop();
          nums.push_back(node);   
        }
        while(count!=0){
            nums.push_back(pivot);
            count--;
        }
       while(!q2.empty()){
          int node = q2.front(); 
          q2.pop();

          nums.push_back(node); 
        }
        return nums;
    }
};