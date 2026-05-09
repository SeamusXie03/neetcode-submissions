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
        int depth = 0;

        stack<pair<TreeNode*, int>> nodeStack;
        nodeStack.push({root, 1});

        while (!nodeStack.empty()) {
            auto [curNode, height] = nodeStack.top();
            nodeStack.pop();

            if (curNode == nullptr) {
                continue;
            }

            depth = max(depth, height);

            nodeStack.push({curNode->right, height + 1});
            nodeStack.push({curNode->left, height + 1});
        }

        return depth;
    }
};
