class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int total = 0;
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;

        for(int i = 0; i<nums.size(); i++){
            total += abs(nums[i] - nums[mid]);

        }
        return total;
        
    }
};