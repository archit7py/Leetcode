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

int fun(TreeNode* node){
    if(node == nullptr){
        return 0;
    }
    int left = fun(node -> left);
    int right = fun(node -> right);

    // int sum = left + right;
    // res = max(res,sum);

    return 1 + max(left,right);
}
    int maxDepth(TreeNode* root) {
        return fun(root);
        
        
    }
};