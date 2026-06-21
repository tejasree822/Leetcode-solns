class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0;
        int count=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins)
        {  sum+=costs[i];
           coins-=costs[i];
           count++;
        }
        else{
            return count;
        }
        }
        return count;
    }
};