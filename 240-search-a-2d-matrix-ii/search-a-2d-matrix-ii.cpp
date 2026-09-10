class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // row
        int m = matrix[0].size();  // column
        int row = matrix.size()-1;
        int col = 0;
        while(row>=0 && col < m){
            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col] > target){
                row--;
            }
            else{
                col++;
            }
        }
        return false;
        
       
        
    }
};