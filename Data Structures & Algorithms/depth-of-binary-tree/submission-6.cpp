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
        if (root == nullptr) {
            return 0;
        }

        int level = 0;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            // number of nodes on the current level
            int size = nodeQueue.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* cur_node = nodeQueue.front();
                nodeQueue.pop();

                if (cur_node->left != nullptr) {
                    nodeQueue.push(cur_node->left);
                }
                
                if (cur_node->right != nullptr) {
                    nodeQueue.push(cur_node->right);
                }
            }

            level++;
        }

        return level;
    }
};
