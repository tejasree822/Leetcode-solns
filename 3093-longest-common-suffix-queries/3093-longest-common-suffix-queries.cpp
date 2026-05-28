class Solution {
public:

    struct Node {

        int child[26];
        int index;
        int len;

        Node() {

            memset(child, -1, sizeof(child));

            index = -1;
            len = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node());
    }

    void insert(string& word, int idx) {

        int node = 0;

        int n = word.size();

        if(n < trie[node].len) {
            trie[node].len = n;
            trie[node].index = idx;
        }

        for(int i = n - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {

                trie[node].child[c] = trie.size();

                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if(n < trie[node].len) {

                trie[node].len = n;
                trie[node].index = idx;
            }
        }
    }

    int search(string& word) {

        int node = 0;

        int ans = trie[node].index;

        for(int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {
                break;
            }

            node = trie[node].child[c];

            ans = trie[node].index;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for(int i = 0; i < wordsContainer.size(); i++) {

            insert(wordsContainer[i], i);
        }

        vector<int> result;

        for(string& q : wordsQuery) {

            result.push_back(search(q));
        }

        return result;
    }
};