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
        ListNode* newHead = new ListNode(-1);
        ListNode* newTail = newHead;
        if(list1 != nullptr && list2 != nullptr) {
            if(list1->val >= list2->val) {
                newTail->next = list2;
                list2 = list2->next;
            } else {
                newTail->next = list1;
                list1 = list1->next;
            }
            newTail = newTail->next;
        }

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val >= list2->val) {
                newTail->next = list2;
                list2 = list2->next;
            } else {
                newTail->next = list1;
                list1 = list1->next;
            }
            newTail = newTail->next;
        }

        while(list1 != nullptr) {
            newTail->next = list1;
            newTail = newTail->next;
            list1 = list1->next;
        }

        while(list2 != nullptr) {
            newTail->next = list2;
            newTail = newTail->next;
            list2 = list2->next;
        }
        return newHead->next;  
    }
};
