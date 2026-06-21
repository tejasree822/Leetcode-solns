class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> hash(100001,0);
        for(int cost:costs){
            hash[cost]++;
        }
        int count=0;
        for(int i=1;i<=100000;i++){
            while(hash[i]>0 && coins>=i){
                hash[i]--;
                coins-=i;
                count++;
            }
        }
        return count;
    }
};