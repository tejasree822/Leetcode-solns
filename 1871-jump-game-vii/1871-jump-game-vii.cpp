class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int m = s.size();
        if (s[m - 1] == '1') return false; 
        queue<int> q;
        q.push(0);
        int max_reached = 0; 
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i == m - 1) return true;
            int start = max(i + minJump, max_reached + 1);
            int end = min(i + maxJump, m - 1);
            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    q.push(j);
                }
            }
            max_reached = max(max_reached, i + maxJump);
        }
        return false;
    }
};