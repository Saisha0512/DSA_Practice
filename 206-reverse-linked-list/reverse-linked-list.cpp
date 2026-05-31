// ITERATIVE APPROACH : 
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
        // base case
        if (head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *prev = NULL, *curr = head;
        while (curr != NULL){
            // storing the next node address, to avoid losing it
            ListNode *next = curr -> next;

            // reversing the connections
            curr -> next = prev;

            // updating the pointers for the next iteration
            prev = curr;
            curr = next;
        }

        return prev;
    }
};