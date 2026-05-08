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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lHeight = dfs(root->left);
        int rHeight = dfs(root->right);

        diameter = max(lHeight + rHeight, diameter);
        return 1 + max(lHeight, rHeight);
    }
};
