class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       vector<long> array;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            array.push_back(grid[i][j]);
        }
       }
       vector<long long>prefix(array.size());
       long long pre=1;

       vector<long long>suffix(array.size());
       long long suf=1;

       for(int k=0;k<array.size();k++){
        
        if(k!=0){
            pre = (pre * (array[k-1] % 12345)) % 12345;
            prefix[k]=pre;
        }
        else if(k==0){
            prefix[k]=1;
        }
       }
       for(int l=array.size()-1;l>=0;l--){
        if(l!=array.size()-1){
            suf=(suf*(array[l+1]%12345))%12345;
            suffix[l]=suf;
        }
        else if(l==array.size()-1){
            suffix[l]=1;
        }
       }
       for(int i=0;i<array.size();i++){
        array[i]=(prefix[i]*suffix[i])%12345;
       }
       for(int a=0;a<m;a++){
        for(int b=0;b<n;b++){
            grid[a][b]=array[a*n+b];
        }
       }
       return grid;

    }
};