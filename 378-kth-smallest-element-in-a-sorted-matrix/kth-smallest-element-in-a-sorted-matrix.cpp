class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>ans;

        for(int i = 0; i<matrix.size(); i++){
            ans.insert(ans.end(),matrix[i].begin(),matrix[i].end());

        }
        sort(ans.begin(),ans.end());
        return ans[k-1];


        
    }
};