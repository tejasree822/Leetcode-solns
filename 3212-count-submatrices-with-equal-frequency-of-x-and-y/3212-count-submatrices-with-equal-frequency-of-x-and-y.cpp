class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;  

        vector<vector<int>> sum(m, vector<int>(n, 0));
        vector<vector<int>> xcnt(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == 'X'){
                    sum[i][j] = 1;
                    xcnt[i][j] = 1;
                }
                else if(grid[i][j] == 'Y'){
                    sum[i][j] = -1;
                }

                if(i > 0){
                    sum[i][j] += sum[i-1][j];
                    xcnt[i][j] += xcnt[i-1][j];
                }
                if(j > 0){
                    sum[i][j] += sum[i][j-1];
                    xcnt[i][j] += xcnt[i][j-1];
                }
                if(i > 0 && j > 0){
                    sum[i][j] -= sum[i-1][j-1];
                    xcnt[i][j] -= xcnt[i-1][j-1];
                }

                if(sum[i][j] == 0 && xcnt[i][j] > 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};