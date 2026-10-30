class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool>vis(nums.size()+1,false);
        for(int i = 0; i<nums.size(); i++){
            if(vis[nums[i]])return nums[i];
            vis[nums[i]] = true;
            
        }
        return -1;
        
    }
};