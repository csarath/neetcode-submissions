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
        ListNode* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }

        ListNode* node = head;
        while (temp) {
            node = node->next;
            temp = temp->next;
        }

        if (head == node) {
            return head->next;
        }

        ListNode* prev = head;
        while (prev->next != node) {
            prev = prev->next;
        }

        prev->next = node->next;
        node->next = nullptr;

        return head;
        
    }
};
