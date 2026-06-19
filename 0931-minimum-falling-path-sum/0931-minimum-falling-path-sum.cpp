class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
       for(int j=0;j<n;j++){
        dp[0][j]=matrix[0][j];
       }
     
       for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int ld=INT_MAX;
            int rd=INT_MAX;
            if(j>0) ld=dp[i-1][j-1];
             int s=dp[i-1][j];
            if(j<n-1) rd=dp[i-1][j+1];
            dp[i][j]=min({ld,s,rd})+matrix[i][j];
        }
       }
       int mini=dp[n-1][0];
       for(int j=0;j<n;j++){
        mini=min(mini,dp[n-1][j]);
       }
       return mini;
    }
};