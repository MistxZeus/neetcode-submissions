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
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        dfs(root,flag);
        return flag;
    }
    int dfs(TreeNode*node,bool &flag){
         if(!node)return 0;
         int leftHeight=dfs(node->left,flag);
         int rightHeight=dfs(node->right,flag);

         if(abs(rightHeight - leftHeight)>1)flag=false;

         return 1+max(leftHeight,rightHeight);
    }
};
