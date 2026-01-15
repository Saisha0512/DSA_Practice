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
        if (head == NULL || head -> next == NULL){
            return head;
        }

        // Recursive Case : 
        ListNode *newHead = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }

    ListNode* mid(ListNode *head){
        // Base Case : 
        if (head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

public:
    void reorderList(ListNode* a) {
        if (a == NULL || a -> next == NULL){
            return;
        }

        ListNode *middle = mid(a);
        ListNode *b = middle -> next;
        middle -> next = NULL;
        b = reverseLL(b);

        while (a && b){
            ListNode *temp1 = a -> next, *temp2 = b -> next;

            // Updating the links :
            a ->  next = b;
            b -> next = temp1;

            a = temp1;
            b = temp2;
        }
    }
};