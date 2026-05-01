class Solution {
public:
void dfs(int r,int c,int m,int n,vector<vector<int>>& grid){
    if(r<0 ||r>=m||c<0||c>=n||grid[r][c]!=1){
        return;
    }
    grid[r][c]=8;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
     for(int i=0;i<4;i++){
        int newRow=r+dr[i];
        int newCol=c+dc[i];
        dfs(newRow,newCol,m,n,grid);
     }

}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
      for(int i=0;i<m;i++){
        if(grid[i][0]==1){
            dfs(i,0,m,n,grid);
        }
        if(grid[i][n-1]==1){
            dfs(i,n-1,m,n,grid);
        }
      }
      for(int j=0;j<n;j++){
        if(grid[0][j]==1){
            dfs(0,j,m,n,grid);
        }
        if(grid[m-1][j]==1){
            dfs(m-1,j,m,n,grid);
        }
      }
      int count=0;

      for(int i=0;i<m;i++ ){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                count++;
            }
        }
      }
       return count;
    }
};