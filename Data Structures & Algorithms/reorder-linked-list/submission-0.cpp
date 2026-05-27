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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* mid = head;
        ListNode* cur = head;
        while (cur && cur->next) {
            mid = mid->next;
            cur = cur->next->next;
        }
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        //Break the list at middle
        mid->next = nullptr;

        //Reverse second half
        ListNode* prev = nullptr;
        ListNode* next = list2;
        while (next) {
            ListNode* temp = next->next;
            next->next = prev;
            prev = next;
            next = temp;
        }
        list2 = prev;

        //Interleave two lists
        while(list1 && list2) {
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
        
    }
};
