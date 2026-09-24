/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = nullptr;
    int fun(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return 0 ;
        }
        int l = fun(root -> left, p,q);
        int r = fun(root -> right, p,q);
        int self = 0;
        if(root == p || root == q){
            self++;
        }
        int total = l + self + r;
        if(total == 2 && ans == nullptr){
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root,p,q);
        return ans;
       
        
    }
};