
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";

        for (int i = 0; i < num.size(); i++) {
            while (!res.empty() && k > 0 && res.back() > num[i]) {
                res.pop_back();
                k--;
            }

            res.push_back(num[i]);
        }

        while (k > 0) {
            res.pop_back();
            k--;
        }

        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        if (res.empty()) {
            return "0";
        }

        return res;
    }
};
        
 