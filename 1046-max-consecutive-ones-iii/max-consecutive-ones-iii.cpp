class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int zerocount = 0;
        int res = 0;
        for(int high = 0; high<nums.size(); high++){
            if(nums[high] == 0){
                zerocount++;
            }
            while(zerocount > k){
                if(nums[low] == 0){
                    zerocount--;
                }
                low++;
            }
            int len = high - low + 1;
            res = max(res,len);

        }
        return res;
        
    }
};