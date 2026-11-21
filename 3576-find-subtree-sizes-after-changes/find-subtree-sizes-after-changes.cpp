class Solution {
public:

    // First DFS: Find the nearest matching ancestor
    void dfs(int node, vector<vector<int>>& adj,
             string& s, vector<int>& newParent,
             vector<int>& last) {

        int ch = s[node] - 'a';

        int previous = last[ch];

        if(previous != -1) {
            newParent[node] = previous;
        }

        last[ch] = node;

        for(auto child : adj[node]) {
            dfs(child, adj, s, newParent, last);
        }

        // Backtracking
        last[ch] = previous;
    }

    // Second DFS: Calculate subtree sizes
    int dfs2(int node, vector<vector<int>>& newAdj,
             vector<int>& ans) {

        int size = 1;

        for(auto child : newAdj[node]) {
            size += dfs2(child, newAdj, ans);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<vector<int>> newAdj(n);

        // Track latest ancestor for each character
        vector<int> last(26, -1);

        // First DFS
        dfs(0, adj, s, newParent, last);

        // Build modified tree
        for(int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Second DFS
        vector<int> ans(n, 0);

        dfs2(0, newAdj, ans);

        return ans;
    }
};