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
        stack<TreeNode*> pStack;
        pStack.push(p);

        stack<TreeNode*> qStack;
        qStack.push(q);

        while (!(pStack.empty()) && !(qStack.empty())) {
            TreeNode* pRoot = pStack.top();
            pStack.pop();

            TreeNode* qRoot = qStack.top();
            qStack.pop();

            bool pNull = (pRoot == nullptr);
            bool qNull = (qRoot == nullptr);

            if (pNull && qNull) {
                continue;
            } else if (pNull || qNull) {
                return false;
            }

            if (pRoot->val != qRoot->val) {
                return false;
            }

            pStack.push(pRoot->left);
            pStack.push(pRoot->right);
            
            qStack.push(qRoot->left);
            qStack.push(qRoot->right);
        } 

        return true; 
    }
};
