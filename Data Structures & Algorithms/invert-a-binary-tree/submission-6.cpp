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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while(!nodeStack.empty()) {
            TreeNode* cur_root = nodeStack.top();

            nodeStack.pop();

            if (cur_root != nullptr) {
                TreeNode* left  = cur_root->left;
                TreeNode* right = cur_root->right;

                cur_root->left  = right;
                cur_root->right = left;

                nodeStack.push(left);
                nodeStack.push(right);
            }
        }

        return root;
    }
};
