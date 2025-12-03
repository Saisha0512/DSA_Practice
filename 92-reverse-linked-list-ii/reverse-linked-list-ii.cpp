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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base Case :
        if (head == NULL || head -> next == NULL){
            return head;
        }

        // Finding the range of the list : 
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;

        // Taking the prev pointer to the node just before left : 
        ListNode *prev = dummy;
        for (int i = 1; i < left; i ++){
            prev = prev -> next;
        }

        // Reversing the required range of the LL : 
        ListNode *curr = prev -> next, *reversed = NULL;
        for (int i = 0; i < (right - left) + 1; i ++){
            ListNode *next = curr -> next;
            curr -> next = reversed;
            reversed = curr;
            curr = next;
        }

        // Updating the LL connections for the reversed LL : 
        prev -> next -> next = curr;
        prev -> next = reversed;

        return dummy -> next;
    }
};