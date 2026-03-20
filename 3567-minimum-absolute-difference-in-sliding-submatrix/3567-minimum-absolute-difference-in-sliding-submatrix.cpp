class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(k == 0) return {};

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for(int i = 0; i <= m - k; i++){
            for(int j = 0; j <= n - k; j++){

                vector<int> sub;

                for(int h = i; h < i + k; h++){
                    for(int q = j; q < j + k; q++){
                        sub.push_back(grid[h][q]);
                    }
                }

                sort(sub.begin(), sub.end());
                sub.erase(unique(sub.begin(), sub.end()), sub.end());

                int mn;

                if(sub.size() == 1){
                    mn = 0;
                } else {
                    mn = INT_MAX;
                    for(int o = 0; o < sub.size()-1; o++){
                        mn = min(mn, abs(sub[o+1] - sub[o]));
                    }
                }

                ans[i][j] = mn;
            }
        }

        return ans;
    }
};