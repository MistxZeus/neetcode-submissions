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
    int goodNodes(TreeNode* root) {
        int maxSoFar=root->val;
        int goodNodes=0;
        dfs(root,maxSoFar,goodNodes);
        return goodNodes;
    }
    void dfs(TreeNode*root,int maxSoFar,int &goodNodes){
        if(!root)return ;
        if(root->val>=maxSoFar){
            goodNodes++;
        }
        maxSoFar=max(root->val,maxSoFar);
        dfs(root->left,maxSoFar,goodNodes);
        dfs(root->right,maxSoFar,goodNodes);
    }
};
