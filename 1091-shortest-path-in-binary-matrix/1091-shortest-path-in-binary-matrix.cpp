class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
       if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
       queue<pair<int,pair<int,int>>>q;
       vector<vector<int>> dist(n,vector<int>(n,1e9));
       dist[0][0]=1;
       q.push({1,{0,0}});
        int drow[]={-1,-1,-1,0,0,1,1,1};
        int dcol[]={-1,0,1,-1,1,-1,0,1};
       while(!q.empty()){
        int dis=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        if(row==n-1 &&col==n-1) return dis;
        for(int i=0;i<8;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            if(nr>=0 &&nr<n && nc>=0 &&nc<n &&grid[nr][nc]==0 &&dis+1<dist[nr][nc]){
                 dist[nr][nc]=dis+1;
                     q.push({dis+1,{nr,nc}});
                }
        }

       }
       return -1;
    }
};