#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long perim = 4LL * side;
        
        vector<long long> pos(n);
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            if (y == 0)         pos[i] = x;
            else if (x == side) pos[i] = (long long)side + y;
            else if (y == side) pos[i] = 2LL * side + (side - x);
            else                pos[i] = 3LL * side + (side - y);
        }
        sort(pos.begin(), pos.end());
        
        // Double the array to handle wrap-around
        vector<long long> p(2 * n);
        for (int i = 0; i < n; ++i) {
            p[i]     = pos[i];
            p[i + n] = pos[i] + perim;
        }
        
        auto canFit = [&](long long d) -> bool {
            for (int i = 0; i < n; ++i) {
                // Pigeonhole: if remaining perimeter can't fit k gaps of size d, skip
                if (p[i + n] - p[i] < (long long)d * k) continue;
                
                int count = 1;
                int last = i;
                
                // Binary search for next valid point instead of linear scan
                while (count < k) {
                    // Find first index >= last with p[idx] >= p[last] + d
                    int idx = (int)(lower_bound(p.begin() + last, p.begin() + i + n, p[last] + d) - p.begin());
                    if (idx >= i + n) break;
                    last = idx;
                    count++;
                }
                
                if (count == k) {
                    // Wrap-around check: gap from last point back to first
                    long long wrap = p[i] + perim - p[last];
                    if (wrap >= d) return true;
                }
            }
            return false;
        };
        
        int low = 1, high = 2 * side, ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFit(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};