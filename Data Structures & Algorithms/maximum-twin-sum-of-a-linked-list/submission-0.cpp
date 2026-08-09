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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }
        return prev;
    }  
public:
    int pairSum(ListNode* head) {
        ListNode* middle = reverseList(middleNode(head));
        int maxSum = -1e9;

        while(middle) {
            maxSum = max(maxSum, middle->val + head->val);
            middle = middle->next;
            head = head->next;
        }
        return maxSum;
    }
};