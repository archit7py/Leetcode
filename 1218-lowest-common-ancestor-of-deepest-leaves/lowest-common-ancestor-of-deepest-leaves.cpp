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
int height(TreeNode* node){
    if(node == nullptr){
        return 0;
    }
    else{
        return max(1+height(node->left),1+height(node->right));
    }
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        if(l > r){
            return lcaDeepestLeaves(root->left);

        }
        else if(l<r){
            return lcaDeepestLeaves(root->right);
        }
        return root;

        
    }
};