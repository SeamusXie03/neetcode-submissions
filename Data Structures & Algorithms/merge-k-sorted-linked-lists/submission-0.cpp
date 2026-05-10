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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto lambda = [] (const auto& a, const auto& b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> minHeap;

        for (auto& head : lists) {
            minHeap.push(head);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* min = minHeap.top();
            minHeap.pop();

            tail->next = min;
            tail = tail->next;

            if (min->next != nullptr) {
                minHeap.push(min->next);
            }
        }

        return dummy.next;
    }
};
