class Solution {
    private:
       vector<string> mp = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};
public:

void solve(int index,string& current,vector<string>& result,string digits){
 
    if(current.size()==digits.size()){
        
       result.push_back(current);
     
            return;
 }

     for(int i=0;i<(mp[digits[index]-'0']).size();i++){
        current.push_back(mp[digits[index]-'0'][i]);
        solve(index+1,current,result,digits);
        current.pop_back();

     }


}
    vector<string> letterCombinations(string digits) {
        string current = "";
        vector<string> result;
       

        solve(0,current,result,digits);
        return result;
    }
};