/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* prev = nullptr;
int wrong = 0;
TreeNode* g1first = nullptr;
TreeNode* g1second = nullptr;
TreeNode* g2first = nullptr;
TreeNode* g2second = nullptr;
void fun(TreeNode* node){
    if(node == nullptr){
        return;
    }
    fun(node -> left);
    if(prev == nullptr){
        prev = node;
    }
    else{
        if(node -> val < prev -> val){
            if(wrong == 0){
                g1first = prev;
                g1second = node;
                wrong++;
            }
            else{
                g2first = prev;
                g2second = node;
                wrong++;
            }
            
        }
        prev = node;
    }
    fun(node -> right);
}
    void recoverTree(TreeNode* root) {
        fun(root);
        if(wrong == 1){
            swap(g1first -> val,g1second -> val);
        }
        else{
            swap(g1first -> val,g2second -> val);
        }
        return;
        
    }
};