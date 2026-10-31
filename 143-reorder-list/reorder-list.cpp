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
        if(head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = second;
        while(curr != nullptr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *first = head;
        ListNode *secondhalf = prev; //prev is the head for the 2nd linked list
        while(secondhalf != nullptr){
            // SAVE THE NEXT NODES
            ListNode *temp = first -> next;
            ListNode *temp1 = secondhalf -> next;
            //Connect
            first -> next = secondhalf;
            secondhalf -> next = temp;
            first = temp;
            secondhalf = temp1;
        }


        
       

        
    }
};