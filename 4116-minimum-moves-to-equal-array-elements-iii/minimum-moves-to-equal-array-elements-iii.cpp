class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += maxi - nums[i];
        }

        return total;
    }
};