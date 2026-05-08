class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
       vector<vector<int>> adj(numCourses);
       for(auto it : prerequisites) {

         int u = it[0];
         int v = it[1];

       adj[v].push_back(u);
}
vector<int> indegree(numCourses,0);
for(int i=0;i<numCourses;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
}
queue<int> q;
for(int i=0;i<numCourses;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
int courses=0;
while(!q.empty()){
    int node=q.front();
    q.pop();
    courses++;
    for(auto it:adj[node]){ indegree[it]--;
    if(indegree[it]==0) q.push(it);
}
}
if(courses!=numCourses ) return false;
else return true;
    }
};