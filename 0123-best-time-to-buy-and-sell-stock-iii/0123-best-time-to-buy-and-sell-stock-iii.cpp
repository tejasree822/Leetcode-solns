class Solution {
public:
int f(int i,int tno,int n,vector<int>& prices,vector<vector<int>>& dp){
    if(i==n||tno==4){
        return 0;
    }
    if(dp[i][tno]!=-1) return dp[i][tno];
    if(tno%2==0){
        return dp[i][tno]=max(-prices[i]+f(i+1,tno+1,n,prices,dp),f(i+1,tno,n,prices,dp));
    }
    else{
        return dp[i][tno]=max(prices[i]+f(i+1,tno+1,n,prices,dp),f(i+1,tno,n,prices,dp));
    }
    return 0;

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));

        return f(0,0,n,prices,dp);

    }
};