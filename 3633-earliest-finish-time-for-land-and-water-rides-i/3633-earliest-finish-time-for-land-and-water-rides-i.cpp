class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int finishLand =
                    landStartTime[i] + landDuration[i];

                ans = min(ans,
                          max(finishLand,
                              waterStartTime[j])
                          + waterDuration[j]);

                int finishWater =
                    waterStartTime[j] + waterDuration[j];

                ans = min(ans,
                          max(finishWater,
                              landStartTime[i])
                          + landDuration[i]);
            }
        }

        return ans;
    }
};