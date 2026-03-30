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
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;

        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        ListNode* temp = head;
        ListNode* reverseHead = prev;
      

        while(reverseHead) {
            ListNode* temp1 = temp->next;
            ListNode* temp2 = reverseHead->next;

            temp->next = reverseHead;
            reverseHead->next = temp1;

            temp = temp1;
            reverseHead = temp2; 
        }  
    }
};
