class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size();
        int n=grid[0].size();
      
       
        vector<vector<int>> matrix(k,vector<int>(k,0));
        for(int j=y;j<y+k;j++){
             vector<int> arr;
             for(int i=x;i<x+k;i++){
                    arr.push_back(grid[i][j]);
                    
                }
                reverse(arr.begin(),arr.end());
                
                   for(int h=0;h<arr.size();h++){
                    grid[h+x][j]=arr[h];
                    
                   }

        }
        return grid;
    }
};