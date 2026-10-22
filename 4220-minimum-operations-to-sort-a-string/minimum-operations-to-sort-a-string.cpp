class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char smallest = *min_element(s.begin(), s.end());
        char largest = *max_element(s.begin(), s.end());

        if (s[0] == smallest || s[n - 1] == largest) return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == smallest || s[i] == largest) return 2;
        }

        return 3;
    }
};