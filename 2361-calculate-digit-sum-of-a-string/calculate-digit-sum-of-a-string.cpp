class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k){
            return s;
        }
        string res = "";
        int i = 0;
        while(s.size() > k){
            res = "";
            for(i = 0; i<s.size(); i+=k){
                int sum = 0;
                for(int j = i; j<i+k&&j<s.size(); j++){
                    sum +=s[j] -'0';

                }
                res += to_string(sum);
                   
            }
            s = res;
        }
        return res;
        
    }
};