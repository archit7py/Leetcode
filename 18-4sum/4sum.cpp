class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // Step 1: Sort the array so we can use two pointers
        // and easily skip duplicate values.
        sort(nums.begin(), nums.end());

        // Store all unique quadruplets whose sum equals target.
        vector<vector<int>> res;

        // Store the size of the array.
        int n = nums.size();

        // Step 2: Fix the first element.
        // We need at least three more elements after i.
        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate values for the first element.
            // This prevents generating the same quadruplets again.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Step 3: Fix the second element.
            // j must come after i, with two elements remaining.
            for (int j = i + 1; j < n - 1; j++) {

                // Skip duplicate values for the second element.
                // j > i + 1 allows the first possible j value.
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                // Step 4: Set the two pointers.
                // left searches for the third element.
                int left = j + 1;

                // right searches for the fourth element.
                int right = n - 1;

                // Continue while the two pointers haven't crossed
                // or met each other.
                while (left < right) {

                    // Calculate the sum of the four selected elements.
                    // long long prevents integer overflow during addition.
                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];

                    // Case 1: We found a valid quadruplet.
                    if (sum == target) {

                        // Add the quadruplet to the answer.
                        res.push_back({
                            nums[i], nums[j], nums[left], nums[right]
                        });

                        // Move both pointers to search for another answer.
                        left++;
                        right--;

                        // Skip duplicate third-element values.
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // Skip duplicate fourth-element values.
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }

                    // Case 2: The sum is too large.
                    // Because the array is sorted, decrease the sum
                    // by moving right to the left.
                    else if (sum > target) {
                        right--;
                    }

                    // Case 3: The sum is too small.
                    // Increase the sum by moving left to the right.
                    else {
                        left++;
                    }
                }
            }
        }

        // Return all the unique quadruplets found.
        return res;
    }
};