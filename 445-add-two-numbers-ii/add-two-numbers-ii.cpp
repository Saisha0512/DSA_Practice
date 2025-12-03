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
    ListNode* reverseLL(ListNode *head){
        // Base Case : 
        if (head -> next == NULL){
            return head;
        }

        // Recursive Case : 
        ListNode *newHead = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newHead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Base Case : 
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }

        // Reversing both the LLs : 
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        // New LL : 
        ListNode* head = new ListNode(-1, NULL);
        ListNode *temp = head;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry){
            // Adding a new node : 
            ListNode *node = new ListNode();
            node -> next = NULL;

            int sum = carry;
            // Adding all the values : 
            if (l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            // Updating the value in the new node : 
            node -> val = sum % 10;
            carry = sum / 10;
            
            // Adding the new node to the end of the LL : 
            temp -> next = node;
            temp = node;
        }

        // Reversing the LL again : 
        head = reverseLL(head -> next);
        return head;
    }
};