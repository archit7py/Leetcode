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
void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(times--) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
         if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* left = head;
        ListNode* right;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;

        int size = k;

        while(left != nullptr) {

            right = left;

            // Find the second node
            for(int i = 0; i < size - 1; i++) {

                if(right == nullptr) {
                    break;
                }

                right = right->next;
            }

            // We have two nodes
            if(right != nullptr) {

                // Save next pair BEFORE reversing
                ListNode* next = right->next;

                // Reverse current pair
                reverse(left, size);

                // Connect previous pair
                if(prevleft != nullptr) {
                    prevleft->next = right;
                }

                // First pair becomes answer
                if(res == nullptr) {
                    res = right;
                }

                // left is now the second node
                prevleft = left;

                // Connect to next pair
                left->next = next;

                // Move to next pair
                left = next;
            }
            else {
                // Only one node remains
                if(prevleft != nullptr) {
                    prevleft->next = left;
                }

                break;
            }
        }

        return res;
        
    }
};