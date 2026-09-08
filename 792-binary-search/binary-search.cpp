class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int res = -1;
        while(low<=high){
            int guess = (low+high)/2;
            if(nums[guess] == target){
                res = guess;
            }
            if(nums[guess] < target){
                low = guess + 1;
            
            }
            else{
                high = guess - 1;
            }
            
        }
        return res;
        
    }
};