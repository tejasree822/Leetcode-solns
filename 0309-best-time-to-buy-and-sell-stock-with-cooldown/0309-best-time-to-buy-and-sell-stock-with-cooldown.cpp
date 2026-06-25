class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
          vector<int> after1(2,0),after2(2,0),curr(2,0);
           for(int i=n-1;i>=0;i--){ 
            for(int buy=0;buy<=1;buy++){ 
                if(buy==1)
                { 
                    curr[1]= max(-prices[i]+after1[0],after1[1]); 
                    } 
                    else
                { 
                    curr[0]=max(prices[i]+after2[1],after1[0]); 
                    } 
                }
                after2=after1;
                after1=curr;
                 }
                  return after1[1]; 
                  } 
                  
        
};
