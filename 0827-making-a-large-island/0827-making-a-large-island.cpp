class DisjointSet {
public:
vector<int> rank,parent,size;
    DisjointSet(int n) {
     rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
    parent[i]=i;
    size[i]=1;
    }  
     }
    int findultpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findultpar(parent[node]);
    }

    bool find(int u, int v) {
        int ulp_u=findultpar(u);
        int ulp_v=findultpar(v);
        if(ulp_u==ulp_v) return true;
        else return false;
    }

    void unionByRank(int u, int v) {
     int ulp_u=findultpar(u);
        int ulp_v=findultpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        
    }

    void unionBySize(int u, int v) {
        int ulp_u=findultpar(u);
        int ulp_v=findultpar(v);
         if(ulp_u==ulp_v) return;
         if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
         }
         else if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];

         }
         else{
             parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];

         }
    }
};
class Solution {
    private:
    bool isvalid(int newrow,int newcol,int n){
    return newrow>=0&&newrow<n&&newcol>=0&&newcol<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               int row=i;
               int col=j;
            if(grid[i][j]==0) continue;
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
          for(int k=0;k<4;k++){
            int newrow=row+dr[k];
            int newcol=col+dc[k];
            if(isvalid(newrow,newcol,n)&&grid[newrow][newcol]==1){ int nodeno=row*n+col;
            int newnodeno=newrow*n+newcol;
                ds.unionBySize(nodeno,newnodeno);

            }
          }
        }
        }
        int mx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
  int row=i;
  int col=j;
          int dr[]={-1,1,0,0};
          int dc[]={0,0,-1,1};
          set<int>components;

          for(int k=0;k<4;k++){
            int newrow=row+dr[k];
            int newcol=col+dc[k];
            if(isvalid(newrow,newcol,n)){
                if(grid[newrow][newcol]==1){
      components.insert(ds.findultpar(newrow*n+newcol));
                }
            }
            }
            int sizetot=0;
            for(auto it:components){
                sizetot+=ds.size[it];
            }
            mx=max(mx,sizetot+1);
        }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findultpar(i)]);
        }
return mx;
    }
};