class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        int count = 0;

        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            count++;

            if(count == k){
                return x;
            }
        }

        return -1;
    }
};