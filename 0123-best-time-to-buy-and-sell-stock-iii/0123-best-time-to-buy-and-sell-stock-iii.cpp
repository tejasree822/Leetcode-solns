class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int i=n-1;i>=0;i--){
            for(int tno=0;tno<=3;tno++){
                if(tno%2==0){
        dp[i][tno]=max(-prices[i]+dp[i+1][tno+1],dp[i+1][tno]);
    }
    else{
        dp[i][tno]=max(prices[i]+dp[i+1][tno+1],dp[i+1][tno]);
    }
            }
        }

        return dp[0][0];

    }
};