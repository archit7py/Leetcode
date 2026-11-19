class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff1 = abs(nums[n-2] - nums[1]);
        int diff2 = abs(nums[2] - nums[n-1]);
        int diff3 = abs(nums[n-3] - nums[0]);
        return min({diff1,diff2,diff3});

        

        

        
    }
};