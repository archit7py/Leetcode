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
bool ans = true;
void ino(TreeNode* node){
    if(node == nullptr){
        return;
    }
    ino(node -> left);
    if(prev == nullptr){
        prev = node;
    }
    else{
        if(node -> val <= prev -> val){
            ans = false;
        }
        prev = node;
    }
    ino(node -> right);
}
    bool isValidBST(TreeNode* root) {
        
        ino(root);
        return ans;
    }
};