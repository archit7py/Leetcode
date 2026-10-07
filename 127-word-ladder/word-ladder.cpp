class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();

        unordered_map<string, int> f;

        // Put all words into the map
        for(int i = 0; i < n; i++) {
            f[wordList[i]] = 1;
        }

        // If endWord doesn't exist, no transformation is possible
        if(f.find(endWord) == f.end()) {
            return 0;
        }

        // Put beginWord into the map
        f[beginWord] = 1;

        queue<pair<string, int>> q;

        // Start with beginWord and length 1
        q.push({beginWord, 1});

        // Mark beginWord as visited
        f.erase(beginWord);

        while(!q.empty()) {

            pair<string, int> p = q.front();
            q.pop();

            string s = p.first;
            int val = p.second;

            if(s == endWord) {
                return val;
            }

            // Change every character
            for(int i = 0; i < s.size(); i++) {

                char c = s[i];

                // Try a-z
                for(char j = 'a'; j <= 'z'; j++) {

                    // Don't replace with same character
                    if(c == j) {
                        continue;
                    }

                    s[i] = j;

                    // If transformed word exists
                    if(f.find(s) != f.end()) {

                        q.push({s, val + 1});

                        // Mark as visited
                        f.erase(s);
                    }
                }

                // Restore original character
                s[i] = c;
            }
        }

        return 0;
    }
};