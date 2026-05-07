/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> ptr;

        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head;
        while (cur->next != nullptr) {
            ptr.push(cur);
            cur = cur->next;
        }

        ListNode* newHead = cur;
        while (!ptr.empty()) {
            cur->next = ptr.top();
            ptr.pop();
            cur = cur->next;
        }
        cur->next = nullptr;

        return newHead;
    }
};
