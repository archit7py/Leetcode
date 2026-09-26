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
bool fun(TreeNode* node,int sum,int target){
    if(node == nullptr){
        return false;
    }
    if(node != nullptr){
        sum += node -> val;
    }
    if(node -> left == nullptr && node -> right == nullptr){
        if(sum == target){
            return true;
        }
    }
    if(fun(node -> left , sum, target)){
        return true;
    }
    if(fun(node -> right, sum, target)){
        return true;
    }
    return false;
    
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return fun(root,sum,targetSum);
        
    

        
    }
};