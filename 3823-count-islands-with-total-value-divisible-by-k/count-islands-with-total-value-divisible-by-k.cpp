class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long sum = 0;
                    stack<pair<int, int>> st;

                    st.push({i, j});
                    visited[i][j] = true;

                    while (!st.empty()) {
                        int r = st.top().first;
                        int c = st.top().second;
                        st.pop();

                        sum += grid[r][c];

                        for (int d = 0; d < 4; d++) {
                            int nr = r + x[d];
                            int nc = c + y[d];

                            if (valid(nr, nc, n, m) &&
                                grid[nr][nc] > 0 &&
                                !visited[nr][nc]) {

                                visited[nr][nc] = true;
                                st.push({nr, nc});
                            }
                        }
                    }

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};