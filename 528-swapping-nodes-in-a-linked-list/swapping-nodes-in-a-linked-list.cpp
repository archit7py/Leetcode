class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0; 
        ListNode *curr = head;
        ListNode *start = head;
        while(curr != nullptr){
            n++;
            curr = curr->next;
        }
        ListNode *slow = head;
        for(int i = 1; i<k; i++){
            slow = slow->next;
        }
        ListNode *fast = head;
        for(int i = 1; i<n-k+1; i++){
            fast = fast->next;
        }
        
        swap(slow->val, fast->val);
        
        return head;

        
    }
};