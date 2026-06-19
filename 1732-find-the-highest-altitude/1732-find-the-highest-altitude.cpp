class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        for(int i=1;i<gain.size();i++){
            gain[i]=gain[i]+gain[i-1];
        }
        int maxi=0;
        for(int i=0;i<gain.size();i++){
            maxi=max(maxi,gain[i]);
        }
        return maxi;
    }
};