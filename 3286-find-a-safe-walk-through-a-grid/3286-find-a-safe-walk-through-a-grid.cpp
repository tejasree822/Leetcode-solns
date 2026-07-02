class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
      greater<pair<int,pair<int,int>>>>pq;
 vector<vector<bool>> visited(m,vector<bool>(n,false));
 vector<vector<int>> dist(m,vector<int>(n,1e9));
 dist[0][0]=grid[0][0];
      int dr[]={-1,1,0,0};
      int dc[]={0,0,-1,1};
      pq.push({grid[0][0],{0,0}});
      
      while(!pq.empty()){
         int safe=pq.top().first;
        int r=pq.top().second.first;
        int c=pq.top().second.second;

        pq.pop();
      if(visited[r][c]==true) continue;
        visited[r][c]=true;

        if(r==m-1 && c==n-1){
            if(safe<health){
                return true;
            }
            return false;
        }
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
           if( nr>=0 &&nr<m &&nc>=0 &&nc<n &&!visited[nr][nc]){
               int newsafe=safe+grid[nr][nc];
               if(newsafe<dist[nr][nc]){
                dist[nr][nc]=newsafe;
               
               }
                pq.push({dist[nr][nc],{nr,nc}});
               
           }
        }
        
      }
      
      return false;

    }
};