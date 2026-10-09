class Solution {
public:
unordered_map<int,int>dp;
    int fib(int n) {
        if(n==0 || n == 1){
            return n;
        }
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        int ans1 = fib(n-1);
        int ans2 = fib(n-2);
        dp[n] = ans1+ans2;
        return ans1+ans2;
        
    }
};