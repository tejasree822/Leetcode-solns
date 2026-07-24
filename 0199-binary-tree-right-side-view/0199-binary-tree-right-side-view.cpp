/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> ds;
void f(TreeNode* node,int level){
    if(node==NULL) return;
    if(level==ds.size()) ds.push_back(node->val);
    f(node->right,level+1);
    f(node->left,level+1);
}

    vector<int> rightSideView(TreeNode* root) {
        f(root,0);
        return ds;
        

    }
};