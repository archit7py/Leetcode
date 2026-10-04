class Solution {
public:

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& a, int n, int m, int i, int j) {

        a[i][j] = '#';

        for(int k = 0; k < 4; k++) {

            int row = i + x[k];
            int col = j + y[k];

            if(valid(row, col, n, m) && a[row][col] == 'O') {
                dfs(a, n, m, row, col);
            }
        }

        return;
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // Top row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                dfs(board, n, m, 0, j);
            }
        }

        // Bottom row
        for(int j = 0; j < m; j++) {
            if(board[n-1][j] == 'O') {
                dfs(board, n, m, n-1, j);
            }
        }

        // Left column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                dfs(board, n, m, i, 0);
            }
        }

        // Right column
        for(int i = 0; i < n; i++) {
            if(board[i][m-1] == 'O') {
                dfs(board, n, m, i, m-1);
            }
        }

        // Convert
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};