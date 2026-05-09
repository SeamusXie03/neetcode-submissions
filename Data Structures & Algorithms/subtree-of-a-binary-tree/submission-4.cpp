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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> nodeS;
        nodeS.push(root);

        while (!nodeS.empty()) {
            TreeNode* curNode = nodeS.top();
            nodeS.pop();

            if (isSameTree(curNode, subRoot)) {
                return true;
            }

            if (curNode->left != nullptr) nodeS.push(curNode->left);
            if (curNode->right != nullptr) nodeS.push(curNode->right);
        }
        
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> nodeS;
        nodeS.push({p, q});

        while (!nodeS.empty()) {
            auto [pR, qR] = nodeS.top();
            nodeS.pop();

            if (pR == nullptr && qR == nullptr) {
                continue;
            } else if (pR == nullptr || qR == nullptr || pR->val != qR->val) {
                return false;
            }

            nodeS.push({pR->left, qR->left});
            nodeS.push({pR->right, qR->right});
        }

        return true;
    }
};
