class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int sum = 0;
        int res = 0;
        unordered_map<int,int>f;
        f[0] = 1;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            int ques = sum-k;class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sum = 0;  // Stores the current prefix sum
        int res = 0;  // Stores the total number of valid subarrays

        // Stores prefix sums and their frequencies
        unordered_map<int, int> f;

        // Handles subarrays starting from index 0
        f[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            // Calculate the current prefix sum
            sum += nums[i];

            // Find the previous prefix sum needed to get sum k
            int ques = sum - k;

            // Get the frequency of the required prefix sum
            int freq = f[ques];

            // Add the number of valid subarrays to the result
            res += freq;

            // Store the current prefix sum in the map
            f[sum]++;
        }

        // Return the total count of subarrays whose sum equals k
        return res;
    }
};
            int freq = f[ques];
            res += freq;
            f[sum]++;
        }
        return res;
        
    }
};