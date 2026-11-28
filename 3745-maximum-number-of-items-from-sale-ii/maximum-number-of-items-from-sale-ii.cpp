class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        int mini = INT_MAX, maxi = 0;

        vector<int> freq(n + 1, 0);

        for(auto &it : items) {
            freq[it[0]]++;
            mini = min(mini, it[1]);
            maxi = max(maxi, it[0]);
        }

        vector<int> gain(maxi + 1, 0);

        for(int i = 1; i <= maxi; i++) {
            for(int j = i; j <= maxi; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        long long ans = 0;

        for(auto &it : items) {
            int price = it[1];

            if(price > 2LL * mini) break;

            int cnt = min(gain[it[0]], budget / price);

            budget -= cnt * price;
            ans += 2LL * cnt;
        }

        return ans + budget / mini;
    }
};