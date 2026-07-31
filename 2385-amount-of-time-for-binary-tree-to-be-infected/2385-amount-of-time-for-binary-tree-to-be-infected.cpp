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
private:
    void buildparent(TreeNode* node,TreeNode* par,unordered_map<TreeNode*,TreeNode*>& parent)
{    if(node==NULL) return;
   parent[node]=par;
    buildparent(node->left,node,parent);
    buildparent(node->right,node,parent);

}
TreeNode* findStartNode(TreeNode* node,int start){
    if(node==NULL) return NULL;
      if(node->val==start) return node;
        TreeNode* left = findStartNode(node->left,start);
        if(left!= NULL) return left;
        return findStartNode(node->right,start);
}
public:
    int amountOfTime(TreeNode* root, int start) {
         unordered_map<TreeNode*,TreeNode*> parent;
          buildparent(root,0,parent);
          unordered_set<TreeNode*> visited;
          queue<TreeNode*> q;
          q.push(findStartNode(root,start));
          visited.insert(findStartNode(root,start));
          int distance=0;
          while(!q.empty()){
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
          return distance-1;
    }
};