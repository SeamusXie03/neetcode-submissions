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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Reverse the list
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // Dummy node
        ListNode node(-1, prev);

        // Remove the node
        int idx = 0;
        curr = &node;
        prev = nullptr;
        while (curr) {
            if (idx == n) {
                prev->next = curr->next;
                curr->next = nullptr;
                break;
            } else {
                prev = curr;
                curr = curr->next;
                idx++;
            }
        }

        // Reverse the list
        curr = node.next;
        prev = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
