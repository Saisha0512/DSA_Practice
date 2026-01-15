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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Base Case : 
        if (head == NULL){
            return NULL;
        }

        // Iterative Case : 
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i ++){
            fast = fast -> next;
        }

        // If the head node is to be removed : 
        if (fast == NULL){
            ListNode *temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        // Otherwise : 
        while (fast -> next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }

        // Deleting the nth node : 
        ListNode *temp = slow -> next;
        slow -> next = temp -> next;
        delete temp;

        return head;
    }
};