class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};