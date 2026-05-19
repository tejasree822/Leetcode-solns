class DisjointSet{
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
    void unionBySize(int u, int v) {
        int ulp_u=findultpar(u);
        int ulp_v=findultpar(v);
         if(ulp_u==ulp_v) return;
         if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
         }
         else{
             parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];

         }
    }

};
class Solution {
    public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        DisjointSet ds(n);
        if(m<n-1) return -1;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            ds.unionBySize(u,v);
        }
        int components=0;
        for(int i=0;i<n;i++){
               if(ds.findultpar(i)==i){
                components++;
               }
        }
        return components-1;

        
    }
};