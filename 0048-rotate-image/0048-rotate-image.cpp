class Solution {
public:
void reverse(vector<int>& matrix,int start,int end){
    while(start<end){
        int temp=matrix[start];
        matrix[start]=matrix[end];
        matrix[end]=temp;
        start++;
        end--;
    }
}
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> temp(m);
        for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
         }
         }

         for(int i=0;i<m;i++){
          reverse(matrix[i],0,n-1);
        }

    }
};