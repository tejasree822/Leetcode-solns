class Solution {
public:
    void solve(int index, const string& num, int target, string path, long long calcValue, long long prevOp, vector<string>& ans) {
        if (index == num.length()) {
            if (calcValue == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long long curNum = stoll(part);

            if (index == 0) {
                solve(i + 1, num, target, part, curNum, curNum, ans);
            } 
            else {
                solve(i + 1, num, target, path + "+" + part, calcValue + curNum, curNum, ans);
                solve(i + 1, num, target, path + "-" + part, calcValue - curNum, -curNum, ans);
                solve(i + 1, num, target, path + "*" + part, (calcValue - prevOp) + (prevOp * curNum), prevOp * curNum, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) return ans;
        
        solve(0, num, target, "", 0, 0, ans);
        return ans;
    }
};