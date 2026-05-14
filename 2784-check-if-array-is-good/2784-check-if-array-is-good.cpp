class Solution {
public:
    bool isGood(vector<int>& nums) {
       
        int n=nums.size();
        
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            
        }
        if((maxi+1)!=n){
            return false;
        }
         vector<long long>hash(maxi+1,0);
         for(int i=0;i<n;i++){
           hash[nums[i]]++;
            
        }
        for(int i=0;i<n;i++){
             if(nums[i]!=maxi){
                if(hash[nums[i]]!=1) return false;
             }
             else if(nums[i]==maxi){
                if(hash[nums[i]]!=2) return false;
             }
        }
        return true;
    }
};