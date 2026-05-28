class Solution {
public:
void solve(int index,vector<char>& current,vector<string>& result,string digits,vector<char>& v){
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
    if(current.size()==digits.size()){
        string temp(current.begin(), current.end());
       result.push_back(temp);
     
            return;
 }

     for(int i=0;i<(mp[v[index]-'0']).size();i++){
        current.push_back(mp[v[index]-'0'][i]);
        solve(index+1,current,result,digits,v);
        current.pop_back();

     }


}
    vector<string> letterCombinations(string digits) {
        vector<char> current;
        vector<string> result;
        vector<char> v(digits.begin(),digits.end());

        solve(0,current,result,digits,v);
        return result;
    }
};