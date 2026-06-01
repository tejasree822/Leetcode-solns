class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int cost1=0,i=0;
        sort(cost.begin(),cost.end());
        int index=n-1;
        while(index >= 0){
            i++;
          if(i%3!= 0)
         cost1+= cost[index];
          index--;
      }
        return cost1;
    }
};