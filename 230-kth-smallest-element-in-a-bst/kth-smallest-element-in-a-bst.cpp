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
int countnodes(TreeNode* node, int k){
    if(node == nullptr){
        return 0;
    }

    return 1 + countnodes(node->left,k) + countnodes(node -> right,k);
}
int fun(TreeNode* node,int k){
    if(node == nullptr){
        return 0;
    }
    int leftcount = countnodes(node->left,k);
    if(k <= leftcount){
        return fun(node -> left,k);
    }
    if( k == leftcount + 1){
        return node -> val;
    }
    
    return fun(node -> right,k-leftcount-1);
    

}
    
    int kthSmallest(TreeNode* root, int k) {
        return fun(root,k);
        
        
    }
};