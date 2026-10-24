class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;       // Starting index of the window
        int res = 0;       // Stores the maximum valid window length
        int maxcount = 0;  // Maximum frequency of a character found so far

        unordered_map<char, int> f; // Stores the frequency of each character

        for (int high = 0; high < s.size(); high++) {

            f[s[high]]++; // Increase the frequency of the current character

            int len = high - low + 1; // Calculate the current window length

            // Update the maximum frequency of any character
            maxcount = max(maxcount, f[s[high]]);

            // Characters that need to be replaced to make the window identical
            int diff = len - maxcount;

            // If replacements needed exceed k, shrink the window
            while (diff > k) {

                f[s[low]]--; // Decrease the frequency of the leftmost character

                low++; // Move the starting index forward

                // Update the window length after shrinking
                len = high - low + 1;

                // Recalculate the number of replacements needed
                diff = len - maxcount;
            }

            // Calculate the length of the current valid window
            len = high - low + 1;

            // Keep the maximum length found so far
            res = max(res, len);
        }

        return res; // Return the longest possible substring length
    }
};