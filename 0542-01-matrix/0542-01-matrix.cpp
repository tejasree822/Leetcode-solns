class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> temp(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                  visited[i][j]=1;
                  q.push({{i,j},0});
                  temp[i][j]=0;

               
                }
            }
        }

            int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};


           while(!q.empty()){
            int r=q.front().first.first;
          int c=q.front().first.second;
         int t=q.front().second;
         q.pop();
         for(int i=0;i<4;i++){
            int nRow=r+drow[i];
            int nCol=c+dcol[i];
         if(nRow>=0 &&nRow<m &&nCol>=0 &&nCol<n &&visited[nRow][nCol]!=1 &&mat[nRow][nCol]==1){
            
            int newt=t+1;
            temp[nRow][nCol]=newt;
            q.push({{nRow,nCol},newt});
            visited[nRow][nCol]=1;

         }




        }
           }
        return temp;
        
    }
};