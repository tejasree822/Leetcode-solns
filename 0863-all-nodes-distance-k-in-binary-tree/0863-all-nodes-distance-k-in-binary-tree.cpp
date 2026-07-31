/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void buildparent(TreeNode* node,TreeNode* par,unordered_map<TreeNode*,TreeNode*>& parent)
{    if(node==NULL) return;
   parent[node]=par;
    buildparent(node->left,node,parent);
    buildparent(node->right,node,parent);

}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          unordered_map<TreeNode*,TreeNode*> parent;
          buildparent(root,0,parent);
          unordered_set<TreeNode*> visited;
          queue<TreeNode*> q;
          q.push(target);
          visited.insert(target);
          int distance=0;
          while(!q.empty()){
            if(distance==k) break;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited.count(curr->left)){
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right && !visited.count(curr->right)){
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if(parent[curr]&& !visited.count(parent[curr])){
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            distance++;
          }
          vector<int> result;
          while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
          }
          return result;
    }

    
};