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
public:
    int removeStones(vector<vector<int>>& stones) {int maxrow=0;
    int n=stones.size();
    int maxcol=0;

    for(auto it:stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
    }
    DisjointSet ds(maxrow+maxcol+1);
    unordered_map<int,int>uniquenodes;
    for(auto it:stones){
        int noderow=it[0];
        int nodecol=it[1]+maxrow+1;
        ds.unionBySize(noderow,nodecol);
       uniquenodes[noderow]=1;
       uniquenodes[nodecol]=1;  
    }
    int cnt=0;
    for(auto it:uniquenodes){
        if(ds.findultpar(it.first)==it.first){
            cnt++;
        }
    }
    return n-cnt;
    }

    
};