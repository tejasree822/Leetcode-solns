class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> hash(26,0);
        for(char ch:text){
            hash[ch-97]++;
        }
       return min({hash['b'-'a'],hash['a'-'a'],hash['l'-'a']/2,hash['o'-'a']/2,hash['n'-'a']});
    }
};