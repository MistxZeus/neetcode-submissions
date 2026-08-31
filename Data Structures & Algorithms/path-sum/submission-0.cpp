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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
      return canReach(root,targetSum,targetSum);
    }
    bool canReach(TreeNode*root,int remaining,int targetSum){
        if(!root)return false;
        remaining-=root->val;
        if(!root->left&&!root->right){
            if(remaining==0)return true;
            remaining+=root->val;
            return false;
        }
        if(canReach(root->left,remaining,targetSum)){
            return true;
        }
        if(canReach(root->right,remaining,targetSum)){
            return true;
        }
        return false;
    }
};