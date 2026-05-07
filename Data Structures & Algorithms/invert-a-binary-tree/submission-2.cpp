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

            if (cur_root != nullptr) {
                nodeStack.pop();

                TreeNode* temp = cur_root->left;
                cur_root->left = cur_root->right;
                cur_root->right = temp;

                nodeStack.push(cur_root->left);
                nodeStack.push(cur_root->right);
            } else {
                nodeStack.pop();
            }
        }

        return root;
    }
};
