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
        vector<int> p(m,0),c(m,0);
     for(int j=0;j<m;j++){
        p[j]=triangle[m-1][j];
     }
     for(int i=m-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+p[j];
            int dg=triangle[i][j]+p[j+1];
            c[j]=min(d,dg);
            
        }
        p=c;

     }
     return p[0];

    }
};