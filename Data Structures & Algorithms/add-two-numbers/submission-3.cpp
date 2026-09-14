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
private:
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // l1 = reverseList(l1);
        // l2 = reverseList(l2);

        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;
        int carry = 0;

        while(l1 || l2 || carry) {
            int sum = carry;
        
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            dummyTail->next = new ListNode(sum % 10);
            dummyTail = dummyTail->next;
        }
        //return reverseList(dummyHead->next);
        return dummyHead->next;
    }
};
