class Solution {
public:
int largestrectanglearea(vector<int>& histo){
    stack<int> st;
    int n=histo.size();
    int maxA=0;
    for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
            int height=histo[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width=i;
            }
            else{
                width=i-st.top()-1;
            }
             maxA=max(maxA,width*height);
        }
        if(i<n){
            st.push(i);
        }
           
    }
    return maxA;

}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxA=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
                height[j]++;
            }
            else{
                height[j]=0;
            }
          }
          int area=largestrectanglearea(height);
        maxA=max(maxA,area);
        }
        
        return maxA;
    }
};