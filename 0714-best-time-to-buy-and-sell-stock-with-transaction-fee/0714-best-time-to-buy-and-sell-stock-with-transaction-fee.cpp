class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
       
        vector<int> after(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
         after[1]=max(-prices[i]+after[0],after[1]);
    }
    else{
        after[0]=max(prices[i]-fee+after[1],after[0]);
    }
            }
            
        }

        return after[1];
    }
};