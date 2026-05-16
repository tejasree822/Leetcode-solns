class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<int>dist(n+1,1e9);
       dist[k]=0;
       vector<vector<pair<int,int>>>adj(n+1);
       for(auto it:times){
        adj[it[0]].push_back({it[1],it[2]});
       }
       priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int tim=pq.top().first;
            int node=pq.top().second;
            pq.pop();
           if(tim > dist[node]) continue;
            for(auto it:adj[node]){
            int adjNode=it.first;
            int wt=it.second;
            if(tim+wt<dist[adjNode]){
                dist[adjNode]=tim+wt;
                pq.push({tim+wt,adjNode});
            }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            else{
             ans=max(ans,dist[i]);
            }
        }
        return ans;





        
    }
};