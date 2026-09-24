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
bool fun(TreeNode* root1, TreeNode* root2){
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }
    if(root1 == nullptr || root2 == nullptr){
        return false;
    }
    if(root1 -> val != root2 -> val){
        return false;
    }
    bool l1 = fun(root1 -> left , root2 -> right);
    bool r2 = fun(root1 -> right, root2 -> left);
    if(l1 == true && r2 == true){
        return true;
    }
    return false;
}
    bool isSymmetric(TreeNode* root) {
        return fun(root -> left , root -> right);


        
    }
};