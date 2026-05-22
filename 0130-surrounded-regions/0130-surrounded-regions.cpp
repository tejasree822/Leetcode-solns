class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

       queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
       if(board[i][0]=='O')
       {q.push({i,0});
      
       board[i][0]='#';
       }
       if(board[i][n-1]=='O')
        {q.push({i,n-1});
     
        board[i][n-1]='#';
        }
        }
        for(int j=0;j<n;j++){
       if(board[0][j]=='O')
       {q.push({0,j});
      
       board[0][j]='#';
       }
       if(board[m-1][j]=='O')
        {q.push({m-1,j});

        board[m-1][j]='#';
        }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(newr>=0&&newr<m&&newc>=0&&newc<n&&board[newr][newc]=='O'){
                    q.push({newr,newc});
                    board[newr][newc]='#';
                    

                }
            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
       
    }
};