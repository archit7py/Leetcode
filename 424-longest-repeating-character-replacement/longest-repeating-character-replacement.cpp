class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;
        int res = 0;
        int maxcount = 0;
        unordered_map<char,int>f;
        for(int high = 0; high<s.size(); high++){
            f[s[high]]++;
            int len = high - low + 1;
            maxcount = max(maxcount,f[s[high]]);
            int diff = len - maxcount; //total me se max freq wale char ko minus
            while(diff > k){
                f[s[low]]--;
                low++;
                maxcount =  max(maxcount, f[s[high]]);
                len = high - low + 1;
                diff = len - maxcount;
            }
            len  = high - low + 1;
            res = max(res,len);

        }
        return res;
        
    }
};