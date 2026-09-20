class Solution {
public:
void fun(string& s,int n,int idx, string diary, vector<string>& res){
    unordered_map<char,string>freq;
        freq['2'] = "abc";
        freq['3'] = "def";
        freq['4'] = "ghi";
        freq['5'] = "jkl";
        freq['6'] = "mno";
        freq['7'] = "pqrs";
        freq['8'] = "tuv";
        freq['9'] = "wxyz";
    if(idx == n){
        res.push_back(diary);
    }
    string choice = freq[s[idx]];
    for(int i = 0;i<choice.size();i++){
        diary.push_back(choice[i]);
        fun(s,n,idx+1,diary,res);
        diary.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
            

        int n = digits.size();
        int idx = 0;
        string diary = "";
        vector<string>res;
        fun(digits,n,idx,diary,res);
        return res;    

        
    }
};