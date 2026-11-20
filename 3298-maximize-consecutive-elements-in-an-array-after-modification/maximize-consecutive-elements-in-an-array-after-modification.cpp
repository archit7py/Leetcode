class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>dp;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int x = nums[i];
            dp[x+1] = dp[x]+1;
            dp[x] = dp[x-1] + 1; 
            ans = max(ans,max(dp[x+1],dp[x]));
        }
        return ans;
        
    }
};