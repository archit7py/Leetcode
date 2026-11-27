class Solution {
public:
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
int valid(int i, int j, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m){
        return false;
    }
    return true;
}
void dfs(vector<vector<char>>&mat, int n, int m , int i, int j, vector<vector<bool>>&vis){
    vis[i][j] = true;
    for(int k=0; k<4; k++){
        int row = i + x[k];
        int col = j + y[k];
        if(valid(row,col,n,m) && mat[row][col] == '1' && vis[row][col] == 0){
            dfs(mat,n,m,row,col,vis);
        }
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int i,j;
        vector<vector<bool>>vis(n);
        for(int i = 0; i<n; i++){
            vector<bool>t(m,0);
            vis[i] = t;
        }
        
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid,n,m,i,j,vis);
                    res++;
                }
            }
        }
        return res;
        
    }
};