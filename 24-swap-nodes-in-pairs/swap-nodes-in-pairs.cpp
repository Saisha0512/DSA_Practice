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
    ListNode* swapPairs(ListNode* head) {
        // Base Case : 
        if (head == NULL || head -> next == NULL){
            return head;
        }

        // Initializing 2 pointers : 
        ListNode *low = head, *high = head -> next;
        while (low -> next -> next != NULL && high -> next -> next != NULL){
            // Swapping the data : 
            int temp = low -> val;
            low -> val = high -> val;
            high -> val = temp;

            // Updating the pointers : 
            low = low -> next -> next;
            high = high -> next -> next;
        }

        // Only one swap is left : 
        int temp = low -> val;
        low -> val = high -> val;
        high -> val = temp;

        // Returning the updated head : 
        return head;
    }
};