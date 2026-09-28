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
int idx;
unordered_map<int,int>mp;
TreeNode* fun(vector<int>&inorder,vector<int>&postorder,int low, int high){
    if(low > high){
        return nullptr;
    }
    TreeNode* node = new TreeNode(postorder[idx]);
    idx--;
    int id = mp[node->val];
    node -> right = fun(inorder,postorder,id+1,high);
    node -> left = fun(inorder,postorder,low,id-1);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = postorder.size()-1;
        for(int i= 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return fun(inorder,postorder,0,inorder.size()-1);
        
    }
};