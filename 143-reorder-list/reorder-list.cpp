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
    void reorderList(ListNode* head) {
        // Base Case : 
        if (head == NULL || head -> next == NULL || head -> next -> next == NULL) {
            return;
        }

        // Reversing list for every iteration : 
        ListNode *temp = head;
        while (temp -> next -> next != NULL){
            temp -> next = reverseLL(temp -> next);
            temp = temp -> next;
        }
    }
};