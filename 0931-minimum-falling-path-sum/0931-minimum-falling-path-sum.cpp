class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n),curr(n);
       for(int j=0;j<n;j++){
        prev[j]=matrix[0][j];
       }
     
       for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int ld=INT_MAX;
            int rd=INT_MAX;
            if(j>0) ld=prev[j-1];
             int s=prev[j];
            if(j<n-1) rd=prev[j+1];
            curr[j]=min({ld,s,rd})+matrix[i][j];
        }
        prev=curr;
       }
       int mini=prev[0];
       for(int j=0;j<n;j++){
        mini=min(mini,prev[j]);
       }
       return mini;
    }
};