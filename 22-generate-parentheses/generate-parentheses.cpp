class Solution {
public:
void fun(int open, int close, int n, string &temp, vector<string>& ans){
    if(open == n && close == n){
        ans.push_back(temp);
    }
    if(open < n){
        temp.push_back('(');
        fun(open + 1,close,n,temp,ans);
        temp.pop_back();
    }
    if(close < open){
        temp.push_back(')');
        fun(open,close + 1,n,temp,ans);
        temp.pop_back();
    }
    return;
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        fun(0,0,n,temp,ans);

        return ans;
        
    }
};