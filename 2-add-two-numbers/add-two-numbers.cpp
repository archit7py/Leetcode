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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // dummy node to simplify list creation
        ListNode* curr = dummy;             // pointer to build the new list
        int carry = 0;                      // stores carry after addition

        // Loop until both lists are empty and no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;  // value from l1
            int y = (l2 != nullptr) ? l2->val : 0;  // value from l2

            int sum = x + y + carry;       // total sum
            carry = sum / 10;              // carry for next digit

            curr->next = new ListNode(sum % 10); // create new node with current digit
            curr = curr->next;

            // Move to next nodes
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next; // skip dummy node
    }
};