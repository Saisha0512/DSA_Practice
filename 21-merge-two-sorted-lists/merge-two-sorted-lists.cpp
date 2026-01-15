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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        // Base Cases : 
        if (!a) return b;
        if (!b) return a;

        // Recursive Case : 
        ListNode *c;
        if (a-> val < b -> val){
            c = a;
            c -> next = mergeTwoLists(a -> next, b);
        }
        else {
            c = b;
            c -> next = mergeTwoLists(a, b -> next);
        }

        return c;
    }
};