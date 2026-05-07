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
    int maxDepth(TreeNode* root) {
        int max_depth = -1;

        stack<tuple<TreeNode*, int>> nodeStack;
        nodeStack.push({root, 0});

        while (!nodeStack.empty()) {
            auto [cur_node, depth] = nodeStack.top();
            nodeStack.pop();

            if (cur_node == nullptr) {
                continue;
            }

            nodeStack.push({cur_node->left, depth + 1});
            nodeStack.push({cur_node->right, depth + 1});
            max_depth = max(max_depth, depth);
        }

        return max_depth + 1;
    }
};
