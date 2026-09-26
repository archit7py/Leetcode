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
int res = 0;
void fun(TreeNode* node,int sum){
    if(node == nullptr){
        return;
    }
    sum = sum*10 + node->val;
    if(node -> left == nullptr && node->right == nullptr){
        res += sum;
        return;
    }
    fun(node -> left,sum);
    fun(node -> right,sum);
    return;


    
    
}
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        fun(root,sum);
        return res;
        
        
    }
};