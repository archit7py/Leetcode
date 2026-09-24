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
    return fun(root1 -> left, root2 -> left)&&
    fun(root1 -> right, root2 -> right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        if(subRoot == nullptr){
            return true;
        }
        if(fun(root,subRoot)){
            return true;
        }
        return isSubtree(root -> left, subRoot)||
        isSubtree(root -> right, subRoot);

        
    }
};