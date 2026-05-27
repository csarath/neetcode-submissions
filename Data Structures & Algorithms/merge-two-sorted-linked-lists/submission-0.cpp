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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        tail->next = tail; 
        while (list1 && list2) {
            ListNode* temp;
            if (list1->val > list2->val) {
                temp = list2;
                list2 = list2->next;
            } else {
                temp = list1;
                list1 = list1->next;
            }
            tail->next = temp;
            tail = temp;
        }

        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        return head->next;
    }
};
