class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        int i = 0;
        while(i < nums.size()){
            if(st.find(nums[i]) != st.end()){
                return nums[i];
            }

            st.insert(nums[i]);
            i++;
        }
        return -1;
        
    }
};