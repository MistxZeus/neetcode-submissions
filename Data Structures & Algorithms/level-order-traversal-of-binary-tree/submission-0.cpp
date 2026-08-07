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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>queue;
        if(root){
            queue.push(root);
        }
        while(queue.size()>0){
            int size=queue.size();
            vector<int>q;
            for(int i=0;i<size;i++){
                TreeNode* node=queue.front();
                queue.pop();
                q.push_back(node->val);
                if(node->left){
                    queue.push(node->left);
                }
                if(node->right){
                    queue.push(node->right);
                }
            }
            res.push_back(q);
        }
        return res;
    }
};
