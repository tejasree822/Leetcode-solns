class Solution {
public:
int f(int ind,vector<int>& arr, int k,int n,vector<int>& dp){
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int maxi=0;
    int length=0;
    int ans=0;
    for(int j=ind;j<min(n,ind+k);j++){
         length++;
         maxi=max(maxi,arr[j]);
         int sum=length*maxi+f(j+1,arr,k,n,dp);
         ans=max(ans,sum);
    }
    return dp[ind]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,n,dp);

    }
};