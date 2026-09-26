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
void fun(TreeNode* node,int sum, int target,vector<int>&res,vector<vector<int>>&ans){
    if(node == nullptr){
        return ;
    }
    sum += node -> val;
    res.push_back(node->val);
    if(node -> left == nullptr && node -> right == nullptr){
        if(sum == target){
            ans.push_back(res);
        }
        res.pop_back();
        return;
    }
    fun(node -> left,sum,target,res,ans);
    fun(node -> right,sum,target,res,ans);
    res.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>res;
        vector<vector<int>>ans;
        fun(root,sum,targetSum,res,ans);
        return ans;

        
    }
};