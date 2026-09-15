class Solution {
public:

    struct cmp {
        bool operator()(pair<char,int>& a, pair<char,int>& b) {
            return a.second < b.second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {

        int s = tasks.size();
        int seat = 1;
        vector<int>res;

        unordered_map<char,int> freq;
        unordered_map<char,int> free;

        for(int i = 0; i < s; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        priority_queue<
            pair<char,int>,
            vector<pair<char,int>>,
            cmp
        > pq;

        // First push ALL tasks
        for(auto i : freq) {
            pq.push({i.first, i.second});
        }

        while(!pq.empty()) {

            vector<pair<char,int>> pulled;

            while(!pq.empty()) {

                pair<char,int> p = pq.top();
                pq.pop();

                char child = p.first;

                // task is free to execute
                if(free[child] <= seat) {

                    res.push_back(child);

                    p.second--;

                    if(p.second > 0) {
                        free[child] = seat + n + 1;
                        pulled.push_back(p);
                    }

                    break;
                }

                else {
                    pulled.push_back(p);
                }
            }

            // Put tasks back
            for(int i = 0; i < pulled.size(); i++) {
                pq.push(pulled[i]);
            }

            seat++;
        }

        return seat - 1;
    }
};