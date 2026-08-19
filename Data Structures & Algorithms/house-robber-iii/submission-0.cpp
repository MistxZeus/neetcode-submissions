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
    int rob(TreeNode* root) {
        auto val_pair=dfs(root);
        return max(val_pair.first,val_pair.second);
    }
    pair<int,int>dfs(TreeNode*root){
         if(root==nullptr)return make_pair(0,0);
         
         auto left=dfs(root->left);
         auto right=dfs(root->right);
         int with_root=root->val+left.second+right.second;
         int without=max(left.first,left.second)+max(right.first,right.second);
         return make_pair(with_root,without);
    }
};