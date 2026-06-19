class Solution {
public:
int f(int i,int j,int m,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    if(i==m-1) return triangle[m-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d=f(i+1,j,m,triangle,dp)+triangle[i][j];
    int dg=f(i+1,j+1,m,triangle,dp)+triangle[i][j];
    return dp[i][j]=min(d,dg);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
     for(int j=0;j<m;j++){
        dp[m-1][j]=triangle[m-1][j];
     }
     for(int i=m-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(d,dg);
        }
     }
     return dp[0][0];

    }
};