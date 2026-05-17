class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;
        vector<int> vis(n,0);

        q.push(start);
        vis[start]=1;

        while(!q.empty()){

            int idx=q.front();
            q.pop();

            if(arr[idx]==0)
                return true;

            int forward = idx + arr[idx];
            int backward = idx - arr[idx];

            if(forward<n && !vis[forward]){
                vis[forward]=1;
                q.push(forward);
            }

            if(backward>=0 && !vis[backward]){
                vis[backward]=1;
                q.push(backward);
            }
        }

        return false;
    }
};