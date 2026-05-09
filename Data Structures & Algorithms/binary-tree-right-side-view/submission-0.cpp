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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        
        while (!nodeQ.empty()) {
            TreeNode* rightMost = nodeQ.back();
            result.push_back(rightMost->val);

            int size = nodeQ.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curNode = nodeQ.front();
                nodeQ.pop();

                if (curNode->left != nullptr) nodeQ.push(curNode->left);
                if (curNode->right != nullptr) nodeQ.push(curNode->right);
            }
        }
        
        return result;
    }
};
