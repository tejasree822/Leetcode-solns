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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mapmailnode;
          int n=accounts.size();
        DisjointSet ds(n);
     
     for(int i=0;i<n;i++){
         for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(mapmailnode.find(mail)==mapmailnode.end())
           { mapmailnode[mail]=i;
           }
           else{
            ds.unionBySize(i,mapmailnode[mail]);
           }
        }
    }
    vector<string> merged[n];
    for(auto it:mapmailnode){
        string mail=it.first;
        int node=ds.findultpar(it.second);
        merged[node].push_back(mail);

    }
    vector<vector<string>>ans;
   for(int i=0;i<n;i++){
    if(merged[i].size()==0) continue;
    sort(merged[i].begin(),merged[i].end());
    vector<string>temp;
    temp.push_back(accounts[i][0]);
    for(auto it:merged[i]){
        temp.push_back(it);
    }
    ans.push_back(temp);

   }
   return ans;
    }
};