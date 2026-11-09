class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Available servers (stores server indices in sorted order)
        set<int> available;

        // Busy servers: {finishTime, serverIndex}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > busy;

        // Stores how many requests each server handles
        vector<int> count(k, 0);

        // Initially, all servers are available
        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // Process each incoming request
        for(int i = 0; i < arrival.size(); i++) {

            // Move all servers that have finished their work
            // from busy to available
            while(!busy.empty() && busy.top().first <= arrival[i]) {

                available.insert(busy.top().second);
                busy.pop();
            }

            // If no server is available, skip this request
            if(available.empty()) {
                continue;
            }

            // Find the preferred server using cyclic order
            int server = i % k;

            // Find the first available server with index >= server
            auto it = available.lower_bound(server);

            // If no such server exists, start from the smallest index
            if(it == available.end()) {
                it = available.begin();
            }

            // Get the selected server index
            int idx = *it;

            // Remove the selected server from available servers
            available.erase(it);

            // Increase the number of requests handled by this server
            count[idx]++;

            // Calculate when this server will finish the current request
            int finishTime = arrival[i] + load[i];

            // Mark the server as busy until finishTime
            busy.push({finishTime, idx});
        }

        // Find the maximum number of requests handled by any server
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        // Collect all servers that handled the maximum number of requests
        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};