class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
      
        vector<int> p(m,0),c(m,0);
     for(int j=0;j<m;j++){
        p[j]=triangle[m-1][j];
     }
     for(int i=m-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+p[j];
            int dg=triangle[i][j]+p[j+1];
            c[j]=min(d,dg);
            
        }
        p=c;

     }
     return p[0];

    }
};