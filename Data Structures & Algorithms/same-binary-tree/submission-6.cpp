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
        queue<pair<TreeNode*, TreeNode*>> nodeQueue;
        nodeQueue.push({p, q});

        while (!nodeQueue.empty()) {
            // number of nodes on the current level
            int levelSize = nodeQueue.size();
            
            for (int i = 0; i < levelSize; i++) {
                auto [pRoot, qRoot] = nodeQueue.front();
                nodeQueue.pop();

                bool pNull = (pRoot == nullptr);
                bool qNull = (qRoot == nullptr);

                if (pNull && qNull) {
                    continue;
                } else if (pNull || qNull || (pRoot->val != qRoot->val)) {
                    return false;
                }

                nodeQueue.push({pRoot->left, qRoot->left});
                nodeQueue.push({pRoot->right, qRoot->right});
            }
        } 

        return true; 
    }
};
