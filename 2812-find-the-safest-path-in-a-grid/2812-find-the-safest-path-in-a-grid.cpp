class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return 0;
        }

            int drow[]={-1,1,0,0};
            int dcol[]={0,0,1,-1};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<vector<int>> dist(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                    visited[i][j]=true;                    
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n &&!visited[nr][nc]){
                      dist[nr][nc]=dist[r][c]+1;
                      visited[nr][nc]=1;
                      q.push({nr,nc});
                }
            }
        }
        
        vector<vector<int>> best(n,vector<int>(n,-1));
         priority_queue<pair<int,pair<int,int>>> pq;
        best[0][0]=dist[0][0];
        pq.push({dist[0][0],{0,0}});
        vector<vector<bool>> visited1(n,vector<bool>(n,false));
       
        while(!pq.empty()){
     int safe=pq.top().first;
     int r=pq.top().second.first;
     int c=pq.top().second.second;

     pq.pop();
      if (r==n-1 && c==n-1)
        return safe;

     if (visited1[r][c])
        continue;
     visited1[r][c] = true;
   
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n &&!visited1[nr][nc]){
        int newSafe = min(safe,dist[nr][nc]);
        if (newSafe > best[nr][nc]) {
            best[nr][nc] = newSafe;
            pq.push({newSafe,{nr,nc}});
            
        }
    }

        }
        }
        return 0;

        

    }
};