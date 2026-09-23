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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        
        if(root == nullptr){
            return res;
        }
        bool ltr = 1;
        q.push(root);
        while(!q.empty()){
            int levelsize = q.size();
            int first = 0;
            int last = q.size()-1;
            vector<int>temp(levelsize);
            while(levelsize--){
                TreeNode* t = q.front();
                q.pop();
                if(ltr == 1){
                    temp[first] = t -> val;
                    first++;
                }
                else{
                    temp[last] = t -> val;
                    last--;
                }
                if(t -> left != nullptr){
                    q.push(t -> left);
                }
                if(t -> right != nullptr){
                    q.push(t -> right);
                }
            }
            res.push_back(temp);
            ltr = 1-ltr;
        }
        return res;
        
    }
};