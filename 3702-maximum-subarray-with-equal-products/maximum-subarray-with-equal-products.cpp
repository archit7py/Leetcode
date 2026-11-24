class Solution {
public:
    int maxLength(vector<int>& nums) {
        int len = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long prod = 1;
            long long lcmVal = 1;
            long long gcdVal = 0;

            for(int j = i; j < nums.size(); j++) {

                // Prevent overflow before multiplication
                if(prod > LLONG_MAX / nums[j]) break;

                prod *= nums[j];

                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = std::lcm(lcmVal, (long long)nums[j]);

                if(prod == lcmVal * gcdVal) {
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};