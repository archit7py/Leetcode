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
    void reorderList(ListNode* head) {

        // If the list is empty or has only one node, no reordering is needed
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        // Step 1: Find the middle of the linked list using slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow by one node
            fast = fast->next->next;    // Move fast by two nodes
        }

        // Step 2: Split the list into two halves
        // 'second' stores the head of the second half
        ListNode *second = slow->next;

        // Disconnect the first half from the second half
        slow->next = nullptr;

        // Step 3: Reverse the second half
        ListNode *prev = nullptr;
        ListNode *curr = second;

        while(curr != nullptr) {

            // Save the next node before changing the link
            ListNode *temp = curr->next;

            // Reverse the current node's link
            curr->next = prev;

            // Move prev and curr one step forward
            prev = curr;
            curr = temp;
        }

        // 'prev' now points to the head of the reversed second half

        // Step 4: Merge the two halves alternately
        ListNode *first = head;
        ListNode *secondhalf = prev;

        while(secondhalf != nullptr) {

            // Save the next nodes from both halves
            ListNode *temp = first->next;
            ListNode *temp1 = secondhalf->next;

            // Connect a node from the first half to the second half
            first->next = secondhalf;

            // Connect that node to the next node from the first half
            secondhalf->next = temp;

            // Move both pointers forward
            first = temp;
            secondhalf = temp1;
        }
    }
};