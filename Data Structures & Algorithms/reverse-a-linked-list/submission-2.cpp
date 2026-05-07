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
        ListNode* prev_ptr = nullptr;
        ListNode* curr_ptr = head;

        while (curr_ptr != nullptr) {
            ListNode* next_ptr = curr_ptr->next;
            curr_ptr->next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }

        return prev_ptr;
    }
};
