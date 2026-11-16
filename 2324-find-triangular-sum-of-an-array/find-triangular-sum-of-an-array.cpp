class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int i = 0;
        vector<int>res;
        while(nums.size()>1){
            res.clear();
            for(int i = 0; i<nums.size()-1; i++){
                int sum = nums[i] + nums[i+1];
                sum = sum%10;
                res.push_back(sum);
            }
            nums = res;
        }
        return nums[i];
                    
                    
                
                

        
    }
};