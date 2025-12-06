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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        // Base Case : 
        if (head == NULL){
            return head;
        }

        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; i ++){
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
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode *temp = slow -> next;
        slow -> next = temp -> next;
        delete temp;

        return head;
    }
};