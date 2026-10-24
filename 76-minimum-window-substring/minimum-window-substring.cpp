class Solution {
public:
    string minWindow(string s, string t) {
        int low = 0;
        int start = 0;
        int minLen = INT_MAX;   // replaces res string

        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> a;
        unordered_map<char, int> b;

        // Count the required characters in t
        for (int high = 0; high < t.size(); high++) {
            b[t[high]]++;
        }

        // Start the sliding window
        for (int high = 0; high < s.size(); high++) {
            a[s[high]]++;

            bool valid = true;
            for (const auto& x : b) {            // const auto& : no copy
                if (a[x.first] < x.second) {
                    valid = false;
                    break;
                }
            }
            while (valid) {
                int len = high - low + 1;
                if (len < minLen) {              // just store indices, no substr here
                    minLen = len;
                    start = low;
                }
                a[s[low]]--;
                low++;

                valid = true;

                for (const auto& x : b) {
                    if (a[x.first] < x.second) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (minLen == INT_MAX) {
            return "";                      // no valid window was ever found
        }
        return s.substr(start, minLen);     // otherwise, cut out the best window

           
    }
};