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
    bool isPalindrome(ListNode* head) {
        vector<int>ans;
        ListNode *temp = head;
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        


        while(temp != nullptr){
            ans.push_back(temp -> val);
            temp = temp->next;
        }
        int slow = 0;
        int fast = ans.size()-1;
        

        while(slow < fast){
            if(ans[slow] != ans[fast]){
                return false;

            }
            slow++;
            fast--;
        }
        return true;
        
    }
};