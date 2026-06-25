class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
       
        int cb=0,cs=0,ab=0,as=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
         cb=max(-prices[i]+as,ab);
    }
    else{
        cs=max(prices[i]-fee+ab,as);
    }
            }
            ab=cb;
            as=cs;
            
        }

        return ab;
    }
};