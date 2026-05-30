class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int m = queries.size();
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        int M = min(50005, max_x + 1);

        class SegmentTree {
            vector<int> tree;
            int n;
        public:
            SegmentTree(int n) : n(n), tree(4 * n, 0) {}
            
            void update(int node, int start, int end, int idx, int val) {
                if (start == end) {
                    tree[node] = val;
                    return;
                }
                int mid = start + (end - start) / 2;
                if (idx <= mid) update(2 * node, start, mid, idx, val);
                else update(2 * node + 1, mid + 1, end, idx, val);
                tree[node] = max(tree[2 * node], tree[2 * node + 1]);
            }

            int query(int node, int start, int end, int l, int r) {
                if (r < start || end < l) return 0;
                if (l <= start && end <= r) return tree[node];
                int mid = start + (end - start) / 2;
                return max(query(2 * node, start, mid, l, r), 
                           query(2 * node + 1, mid + 1, end, l, r));
            }
        } st(M);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(M);
        st.update(1, 0, M, M, M);
        vector<bool> ans;
        ans.reserve(m);
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.lower_bound(x);
                int R = *it;
                int L = *prev(it);
                obstacles.insert(x);
                st.update(1, 0, M, R, R - x);
                st.update(1, 0, M, x, x - L);
            } else {
                int x = q[1];
                int sz = q[2];
                auto it = obstacles.upper_bound(x);
                int L = *prev(it);
                int max_left_gap = st.query(1, 0, M, 0, L);
                int current_tail_gap = x - L;
                ans.push_back(max(max_left_gap, current_tail_gap) >= sz);
            }
        }
        return ans;
    }
};