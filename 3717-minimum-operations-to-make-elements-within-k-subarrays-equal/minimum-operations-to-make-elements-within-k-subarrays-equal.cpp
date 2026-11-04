class Solution {
public:
    multiset<int> left, right;
    long long leftSum = 0, rightSum = 0;

    // Balance the two halves
    void balance() {
        while (left.size() > right.size() + 1) {
            int val = *left.rbegin();

            left.erase(left.find(val));
            leftSum -= val;

            right.insert(val);
            rightSum += val;
        }

        while (left.size() < right.size()) {
            int val = *right.begin();

            right.erase(right.find(val));
            rightSum -= val;

            left.insert(val);
            leftSum += val;
        }
    }

    // Insert an element
    void add(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            leftSum += val;
        }
        else {
            right.insert(val);
            rightSum += val;
        }

        balance();
    }

    // Remove an element
    void remove(int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            leftSum -= val;
        }
        else {
            it = right.find(val);
            right.erase(it);
            rightSum -= val;
        }

        balance();
    }

    // Calculate window cost
    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - leftSum
             + rightSum - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        left.clear();
        right.clear();
        leftSum = 0;
        rightSum = 0;

        vector<long long> cost;

        // Step 1: Calculate window costs

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost.push_back(getCost());

        for (int i = x; i < n; i++) {
            remove(nums[i-x]);
            add(nums[i]);

            cost.push_back(getCost());
        }

        // Step 2: DP

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n+1, vector<long long>(k+1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Skip
                dp[i][j] = dp[i-1][j];

                // Take
                if (i >= x && dp[i-x][j-1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i-x] + dp[i-x][j-1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};