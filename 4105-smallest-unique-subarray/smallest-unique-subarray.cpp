class Solution {
public:

    bool check(vector<int>& nums, int len) {

        int n = nums.size();

        long long base1 = 31;
        long long base2 = 37;

        long long mod1 = 1000000007;
        long long mod2 = 1000000009;

        unordered_map<unsigned long long, int> mp;

        long long power1 = 1;
        long long power2 = 1;

        // Calculate power
        for(int i = 1; i < len; i++) {

            power1 = (power1 * base1) % mod1;
            power2 = (power2 * base2) % mod2;

        }

        // Calculate initial hash
        long long hash1 = 0;
        long long hash2 = 0;

        for(int i = 0; i < len; i++) {

            hash1 = (hash1 * base1 + nums[i]) % mod1;
            hash2 = (hash2 * base2 + nums[i]) % mod2;

        }

        unsigned long long key =
            ((unsigned long long)hash1 << 32) | hash2;

        mp[key]++;

        // Sliding window
        for(int i = len; i < n; i++) {

            hash1 = (hash1 - nums[i-len] * power1 % mod1 + mod1) % mod1;
            hash1 = (hash1 * base1 + nums[i]) % mod1;

            hash2 = (hash2 - nums[i-len] * power2 % mod2 + mod2) % mod2;
            hash2 = (hash2 * base2 + nums[i]) % mod2;

            key = ((unsigned long long)hash1 << 32) | hash2;

            mp[key]++;
        }

        // Check frequency
        for(auto x : mp) {

            if(x.second == 1) {
                return true;
            }

        }

        return false;
    }


    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        int low = 1;
        int high = n;
        int ans = n;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(check(nums, mid)) {

                ans = mid;
                high = mid - 1;

            }
            else {

                low = mid + 1;

            }
        }

        return ans;
    }
};