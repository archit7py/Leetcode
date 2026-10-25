class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v = nums;
        sort(v.begin(),v.end());

        int low = 0;
        int high = nums.size()-1;

        while(low < nums.size() && nums[low] == v[low]){
            low++;
        }

        while(high > 0 && nums[high] == v[high]){
            high--;
        }

        if(low >= high){
            return 0;
        }

        return high - low + 1;

        
    }
};