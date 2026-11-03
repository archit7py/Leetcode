class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int k = 0;
        ListNode* curr = head;

        // Step 1: Calculate the size of the linked list
        while (curr != nullptr) {
            k++;
            curr = curr->next;
        }

        // Step 2: Find the position of the node to delete
        int deletion = k - n;

        // Step 3: If the first node needs to be deleted
        if (deletion == 0) {
            return head->next;
        }

        // Step 4: Move to the node before the one to delete
        ListNode* another = head;

        for (int i = 0; i < deletion - 1; i++) {
            another = another->next;
        }

        // Step 5: Get the node that needs to be deleted
        ListNode* temp = another->next;

        // Step 6: Skip the node to delete it from the linked list
        another->next = temp->next;

        // Step 7: Return the updated linked list
        return head;
    }
};