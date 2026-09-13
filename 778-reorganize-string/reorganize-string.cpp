class Solution {
public:

    struct cmp {
        bool operator()(pair<char,int>& a, pair<char,int>& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {

        int n = s.size();
        string res = "";
        int seat = 0;

        priority_queue<
            pair<char,int>,
            vector<pair<char,int>>,
            cmp
        > pq;

        unordered_map<char,int> mp;

        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        for(auto i : mp) {
            char word = i.first;
            int freq = i.second;

            pair<char,int> curr = {word, freq};
            pq.push(curr);
        }

        while(!pq.empty()) {

            pair<char,int> curr = pq.top();
            pq.pop();

            // curr is different from previous character
            if(seat == 0 || res[seat-1] != curr.first) {

                res.push_back(curr.first);
                seat++;

                curr.second--;

                if(curr.second > 0) {
                    pq.push(curr);
                }
            }

            // curr is same as previous character
            else {

                if(pq.empty()) {
                    return "";
                }

                pair<char,int> curr1 = pq.top();
                pq.pop();

                res.push_back(curr1.first);
                seat++;

                curr1.second--;

                if(curr1.second > 0) {
                    pq.push(curr1);
                }

                // curr was not used, so put it back
                pq.push(curr);
            }
        }

        return res;
    }
};