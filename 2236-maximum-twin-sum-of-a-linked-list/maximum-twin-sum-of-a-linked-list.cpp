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
    int pairSum(ListNode* head) {
        vector<int> res;
        ListNode *slow = head, *fast = head;

        // pushing the first half of the list into a vector
        while (fast && fast -> next){
            res.push_back(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // starting with the second half of the list
        int i = res.size() - 1;
        while (slow){
            res[i --] += slow -> val;
            slow = slow -> next;
        }

        // finding the maximum twin sum
        int maxsum = *max_element(res.begin(), res.end());

        return maxsum;
    }
};