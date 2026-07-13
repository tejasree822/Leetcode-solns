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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        long long ans=0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
           unsigned long long mmin=q.front().second;
            unsigned long long first,last;
            for(int i=0;i<s;i++){
                unsigned long long curr_id=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=curr_id;
                if(i==s-1) last=curr_id;
                if(node->left) q.push({node->left,2*curr_id+1});
                if(node->right) q.push({node->right,2*curr_id+2});
            }
            ans=max(ans,(long long)(last-first+1));
        }
        return (int)(ans);
    }
};