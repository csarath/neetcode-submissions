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
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {return a->val > b->val;}
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq(lists.begin(), lists.end());

        while (!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if (tail->next)
                pq.push(tail->next);
            tail->next = nullptr;
        }

        return head->next;
        
    }
};
