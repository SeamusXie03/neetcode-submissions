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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);

        vector<vector<int>> result;

        while (!nodeQ.empty()) {
            int size = nodeQ.size();

            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* curNode = nodeQ.front();
                nodeQ.pop();
                
                if (curNode != nullptr) {
                    level.push_back(curNode->val);

                    nodeQ.push(curNode->left);
                    nodeQ.push(curNode->right);
                }
            }

            if (!level.empty()) {
                result.push_back(level);
            }
        }

        return result;
    }
};
