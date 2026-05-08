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
        bool result = true;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* root, bool& result) {
        if (root == nullptr) {
            return 0;
        }

        int lHeight = dfs(root->left, result);
        int rHeight = dfs(root->right, result);

        if (result) {
            result = abs(lHeight - rHeight) <= 1;
        }

        return 1 + max(lHeight, rHeight);
    }
};
