class Solution {
   
public:
bool solve(int row,int col,vector<vector<char>>& board, string word,int index){
     int m=board.size();
        int n=board[0].size();
    if(index==word.size()) return true;
    if(row<0||row>m-1||col<0||col>n-1||board[row][col]!=word[index]){
        return false;
    }
    char temp=board[row][col];
    board[row][col]='#';

        bool found =
            solve(row + 1, col, board, word, index + 1) ||
            solve(row - 1, col, board, word, index + 1) ||
            solve(row, col + 1, board, word, index + 1) ||
            solve(row, col - 1, board, word, index + 1);
board[row][col]=temp;
return found;

}
    bool exist(vector<vector<char>>& board, string word) {
         int m=board.size();
        int n=board[0].size();
      
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;

    }
};  