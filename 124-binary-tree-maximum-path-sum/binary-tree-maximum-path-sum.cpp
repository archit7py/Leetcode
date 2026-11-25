class Solution {
public:
int ans = INT_MIN;
int fun(TreeNode* node){
    if(node == nullptr){
        return 0;
    }
    int left = max(0,fun(node->left));
    int right = max(0,fun(node->right));
    int sum = node->val + left + right;
    ans = max(sum,ans);
    return node->val + max(left,right);

}
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
        
    }
};