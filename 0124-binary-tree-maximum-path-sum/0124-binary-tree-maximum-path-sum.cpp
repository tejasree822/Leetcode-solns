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
int ans=INT_MIN;
   int f(TreeNode* node){
     if(node==NULL) return 0;
     int lg=max(0,f(node->left));
     int rg=max(0,f(node->right));
     int p=node->val+lg+rg;
     ans=max(ans,p);
   return node->val+max(lg,rg);
   }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};