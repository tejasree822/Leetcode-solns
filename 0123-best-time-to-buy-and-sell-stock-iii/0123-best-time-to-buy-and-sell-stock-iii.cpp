class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> after(5,0);
        vector<int>curr(5,0);
        for(int i=n-1;i>=0;i--){
            for(int tno=0;tno<=3;tno++){
                if(tno%2==0){
        curr[tno]=max(-prices[i]+after[tno+1],after[tno]);
    }
    else{
        curr[tno]=max(prices[i]+after[tno+1],after[tno]);
    }
            }
            after=curr;
        }

        return after[0];

    }
};