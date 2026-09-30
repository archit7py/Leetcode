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
int fun(TreeNode* root){
    if(root == nullptr){
        return 0 ;
    }
    int left = fun(root -> left);
    int right = fun(root -> right);

    if(left == 0){
        return 1 + right;
    }
    if(right == 0){
        return 1 + left;
    }

    return 1 + min(left,right);
}
    int minDepth(TreeNode* root) {
        return fun(root);
        
    }
};