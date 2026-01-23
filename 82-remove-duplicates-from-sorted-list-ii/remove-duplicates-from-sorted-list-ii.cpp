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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL){
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *prev = dummy, *curr = head;
        while (curr){
            bool duplicate = false;

            while (curr -> next && curr -> val == curr -> next -> val){
                duplicate = true;
                ListNode *temp = curr;
                curr = curr -> next;
                delete temp;
            }

            if (duplicate){
                ListNode *temp = curr;
                curr = curr -> next;
                delete temp;
                prev -> next = curr;
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }

        return dummy -> next;
    }
};