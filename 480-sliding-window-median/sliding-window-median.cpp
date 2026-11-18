class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        priority_queue<int> maxHeap;
        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int maxSize = 0;
        int minSize = 0;

        // Clean invalid elements from maxHeap
        auto cleanMax = [&]() {
            while(!maxHeap.empty() && mp[maxHeap.top()] > 0) {
                mp[maxHeap.top()]--;
                maxHeap.pop();
            }
        };

        // Clean invalid elements from minHeap
        auto cleanMin = [&]() {
            while(!minHeap.empty() && mp[minHeap.top()] > 0) {
                mp[minHeap.top()]--;
                minHeap.pop();
            }
        };

        // Balance both heaps
        auto balance = [&]() {
            cleanMax();
            cleanMin();

            while(maxSize > minSize) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();

                maxSize--;
                minSize++;

                cleanMax();
            }

            while(minSize > maxSize + 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();

                minSize--;
                maxSize++;

                cleanMin();
            }
        };

        // Insert an element
        auto addNum = [&](int x) {
            cleanMax();
            cleanMin();

            if(maxHeap.empty()) {
                if(!minHeap.empty() && x > minHeap.top()) {
                    minHeap.push(x);
                    minSize++;
                }
                else {
                    maxHeap.push(x);
                    maxSize++;
                }
            }
            else if(x <= maxHeap.top()) {
                maxHeap.push(x);
                maxSize++;
            }
            else {
                minHeap.push(x);
                minSize++;
            }

            balance();
        };

        // Remove an element using lazy deletion
        auto removeNum = [&](int x) {
            cleanMax();
            cleanMin();

            mp[x]++;

            if(!maxHeap.empty() && x <= maxHeap.top()) {
                maxSize--;

                if(x == maxHeap.top()) {
                    cleanMax();
                }
            }
            else {
                minSize--;

                if(!minHeap.empty() && x == minHeap.top()) {
                    cleanMin();
                }
            }

            balance();
        };

        // Insert first k elements
        for(int j = 0; j < k; j++) {
            addNum(nums[j]);
        }

        // Calculate first median
        if(k % 2 == 0) {
            ans.push_back(((double)maxHeap.top() + minHeap.top()) / 2.0);
        }
        else {
            ans.push_back(minHeap.top());
        }

        // Slide the window
        for(int i = k; i < nums.size(); i++) {

            int outgoing = nums[i-k];
            int incoming = nums[i];

            // Remove outgoing element
            removeNum(outgoing);

            // Insert incoming element
            addNum(incoming);

            // Calculate median
            if(k % 2 == 0) {
                ans.push_back(((double)maxHeap.top() + minHeap.top()) / 2.0);
            }
            else {
                ans.push_back(minHeap.top());
            }
        }

        return ans;
    }
};