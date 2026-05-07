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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> nodeStack;
        nodeStack.push({p, q});

        while (!nodeStack.empty()) {
            auto [pRoot, qRoot] = nodeStack.top();
            nodeStack.pop();

            bool pNull = (pRoot == nullptr);
            bool qNull = (qRoot == nullptr);

            if (pNull && qNull) {
                continue;
            } else if (pNull || qNull || (pRoot->val != qRoot->val)) {
                return false;
            }

            nodeStack.push({pRoot->left, qRoot->left});
            nodeStack.push({pRoot->right, qRoot->right});
        } 

        return true; 
    }
};
