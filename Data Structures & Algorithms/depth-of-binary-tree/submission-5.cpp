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
        int max_depth = 0;

        queue<pair<TreeNode*, int>> nodeQueue;
        nodeQueue.push({root, 1});

        while (!nodeQueue.empty()) {
            auto [cur_node, depth] = nodeQueue.front();
            nodeQueue.pop();

            if (cur_node == nullptr) {
                continue;
            }

            nodeQueue.push({cur_node->left, depth + 1});
            nodeQueue.push({cur_node->right, depth + 1});
            max_depth = max(max_depth, depth);
        }

        return max_depth;
    }
};
