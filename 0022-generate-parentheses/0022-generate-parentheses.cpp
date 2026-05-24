class Solution {
    private:
    int open=0;
    int close=0;
public:
void backtrack(int n,vector<string>& result,string& curr){
     if(curr.size()==2*n){
        result.push_back(curr);
        return;
     }

     if(curr.empty()){
        curr.push_back('(');
        open++;
     }
     if(open<n){
        curr.push_back('(');
        open++;
        backtrack(n,result,curr);
        curr.pop_back();
       open--;
     }
     if(close<open){
        curr.push_back(')');
        close++;
        backtrack(n,result,curr);
        curr.pop_back();
       close--;
     }

}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(n,result,current);
        return result;
    }
};