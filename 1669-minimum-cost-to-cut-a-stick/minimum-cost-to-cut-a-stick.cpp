class Solution {
public:
    // Recursive function with memoization
    // i and j represent the indices of cuts we still need to make.
    // dp[i][j] stores the minimum cost to perform all cuts from i to j.
    int fun(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {

        // Base case: No cuts are left to make.
        if(i > j) {
            return 0;
        }

        // If this subproblem has already been solved, reuse its result.
        // This avoids recalculating the same range of cuts.
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Initialize the minimum cost to the largest possible integer.
        int res = INT_MAX;

        // Try every cut from i to j as the FIRST cut to make.
        for(int k = i; k <= j; k++) {

            // Current stick length:
            // cuts[i-1] is the left boundary.
            // cuts[j+1] is the right boundary.
            int cost = cuts[j+1] - cuts[i-1];

            // Total cost =
            // 1. Cost of making the current cut.
            // 2. Minimum cost of cutting the left section.
            // 3. Minimum cost of cutting the right section.
            int r = cost
                    + fun(cuts, i, k-1, dp)
                    + fun(cuts, k+1, j, dp);

            // Keep the minimum cost among all possible first cuts.
            res = min(res, r);
        }

        // Store the answer in dp so we can reuse it later.
        return dp[i][j] = res;
    }

    int minCost(int n, vector<int>& cuts) {

        // Add the two boundaries of the stick.
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort the cut positions so their indices match their order on the stick.
        sort(cuts.begin(), cuts.end());

        // Total number of positions, including 0 and n.
        int s = cuts.size();

        // dp[i][j] = minimum cost to perform cuts[i] through cuts[j].
        // -1 means that the state has not been calculated yet.
        vector<vector<int>> dp(s, vector<int>(s, -1));

        // Initially, we need to perform all actual cuts.
        // Index 0 is the left boundary, and index s-1 is the right boundary.
        return fun(cuts, 1, s-2, dp);
    }
};