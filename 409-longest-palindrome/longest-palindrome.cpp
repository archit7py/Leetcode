class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>need;
        int res = 0;
        bool odd = false;
        for(int i = 0;i<s.size();i++){
            need[s[i]]++;
        }
        for(auto i : need){
            int val = i.second;
            if(val % 2 == 0){
                res += val;
            }
            else{
                odd = true;
            }

        }
        if(odd == false){
            return res;
        }
        for(auto i : need){
            int val = i.second;
            if(val % 2 == 1){
                res += val - 1;
            }
        }
        return res + 1;
        
    }
};