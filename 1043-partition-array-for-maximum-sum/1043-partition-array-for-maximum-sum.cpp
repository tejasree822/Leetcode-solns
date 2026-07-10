class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        int maxi=0;
    int length=0;
    int ans=0;
    for(int j=ind;j<min(n,ind+k);j++){
         length++;
         maxi=max(maxi,arr[j]);
         int sum=length*maxi+dp[j+1];
         ans=max(ans,sum);
    }
   dp[ind]=ans;
}
    
        return dp[0];

    }
};