class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> water;

        for(int i = 0; i < m; i++)
            water.push_back({waterStartTime[i], waterDuration[i]});

        sort(water.begin(), water.end());

        vector<int> startsW(m);
        vector<long long> prefDurW(m);
        vector<long long> suffOpenFinishW(m);

        for(int i = 0; i < m; i++)
            startsW[i] = water[i].first;

        prefDurW[0] = water[0].second;
        for(int i = 1; i < m; i++)
            prefDurW[i] = min(prefDurW[i-1],
                              (long long)water[i].second);

        suffOpenFinishW[m-1] =
            (long long)water[m-1].first + water[m-1].second;

        for(int i = m-2; i >= 0; i--)
            suffOpenFinishW[i] =
                min(suffOpenFinishW[i+1],
                    (long long)water[i].first + water[i].second);

        for(int i = 0; i < n; i++) {

            long long finishLand =
                (long long)landStartTime[i] + landDuration[i];

            int pos =
                upper_bound(startsW.begin(),
                            startsW.end(),
                            finishLand)
                - startsW.begin();

            if(pos > 0)
                ans = min(ans,
                          finishLand + prefDurW[pos-1]);

            if(pos < m)
                ans = min(ans,
                          suffOpenFinishW[pos]);
        }

        vector<pair<int,int>> land;

        for(int i = 0; i < n; i++)
            land.push_back({landStartTime[i], landDuration[i]});

        sort(land.begin(), land.end());

        vector<int> startsL(n);
        vector<long long> prefDurL(n);
        vector<long long> suffOpenFinishL(n);

        for(int i = 0; i < n; i++)
            startsL[i] = land[i].first;

        prefDurL[0] = land[0].second;
        for(int i = 1; i < n; i++)
            prefDurL[i] =
                min(prefDurL[i-1],
                    (long long)land[i].second);

        suffOpenFinishL[n-1] =
            (long long)land[n-1].first + land[n-1].second;

        for(int i = n-2; i >= 0; i--)
            suffOpenFinishL[i] =
                min(suffOpenFinishL[i+1],
                    (long long)land[i].first + land[i].second);

        for(int i = 0; i < m; i++) {

            long long finishWater =
                (long long)waterStartTime[i] + waterDuration[i];

            int pos =
                upper_bound(startsL.begin(),
                            startsL.end(),
                            finishWater)
                - startsL.begin();

            if(pos > 0)
                ans = min(ans,
                          finishWater + prefDurL[pos-1]);

            if(pos < n)
                ans = min(ans,
                          suffOpenFinishL[pos]);
        }

        return ans;
    }
};