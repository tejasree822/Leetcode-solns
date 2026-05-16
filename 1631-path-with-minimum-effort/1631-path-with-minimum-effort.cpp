class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(
            n, vector<int>(m,1e9)
        );

        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;

        effort[0][0]=0;

        pq.push({0,{0,0}});

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!pq.empty()){

            int currEffort=pq.top().first;

            int r=pq.top().second.first;
            int c=pq.top().second.second;

            pq.pop();

            if(r==n-1 && c==m-1)
                return currEffort;

            for(int i=0;i<4;i++){

                int nr=r+drow[i];
                int nc=c+dcol[i];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m){

                    int wt=
                    abs(
                    heights[r][c]-
                    heights[nr][nc]
                    );

                    int newEffort=
                    max(currEffort,wt);

                    if(newEffort<
                       effort[nr][nc]){

                        effort[nr][nc]=
                        newEffort;

                        pq.push(
                        {
                          newEffort,
                          {nr,nc}
                        });
                    }
                }
            }
        }

        return 0;
    }
};