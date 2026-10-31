class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        vector<int> ans;
        vector<int> last;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                res.push_back(nums[i]);
            }
            else {
                ans.push_back(nums[i]);
            }
        }

        int i = 0;
        int j = 0;

        while(i < ans.size() && j < res.size()) {
            last.push_back(ans[i]);
            last.push_back(res[j]);

            i++;
            j++;
        }

        return last;
    }
};