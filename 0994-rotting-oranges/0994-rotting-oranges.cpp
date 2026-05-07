class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
  int time=0;
  int drow[]={-1,0,1,0};
  int dcol[]={0,1,0,-1};

  while(!q.empty()){
    int r=q.front().first.first;
    int c=q.front().first.second;
    int t=q.front().second;
      time=max(time,t);
    q.pop();
    for(int i=0;i<4;i++){
        int nRow=r+drow[i];
        int nCol=c+dcol[i];
        if(nRow>=0 &&nRow<n &&nCol>=0 &&nCol<m &&vis[nRow][nCol]!=2 &&grid[nRow][nCol]==1){
            q.push({{nRow,nCol},t+1});
            vis[nRow][nCol]=2;

        }
    }


  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(vis[i][j]!=2 && grid[i][j]==1){
            return -1;
        }
    }
  }
  return time;

        
    }
};