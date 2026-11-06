class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), compare);

        vector<pair<int,int>> p;

        for(int i = 0; i < queries.size(); i++) {
            p.push_back({queries[i], i});
        }

        sort(p.begin(), p.end());

        unordered_map<int,int> mp;

        vector<int> ans(queries.size());

        int l = 0;
        int r = 0;

        for(auto it : p) {

            int start = it.first - x;
            int end = it.first;
            int idx = it.second;

            while(r < logs.size() && logs[r][1] <= end) {
                mp[logs[r][0]]++;
                r++;
            }

            while(l < logs.size() && logs[l][1] < start) {

                mp[logs[l][0]]--;

                if(mp[logs[l][0]] == 0) {
                    mp.erase(logs[l][0]);
                }

                l++;
            }

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};