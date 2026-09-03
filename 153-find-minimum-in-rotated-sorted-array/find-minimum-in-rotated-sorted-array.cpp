class Solution {
public:
    int findMin(vector<int>& nums) {
        int low  = 0;
        int high = nums.size()-1;
        
        while(low<high){
            int guess = (low + high)/2;
            if(nums[guess]>nums[high]){
                low = guess+1;
            }
            else {
                high = guess;

            }
        }
        return nums[low];
        
    }
};