class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int>t(3); // 2 changing variable so 2+1(extra) = 3
            dp[i] = t;
        }
        for(int k = 0; k <= 2; k++){ 
            dp[n][k] = 0;
        }
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i = n-1; i>=0; i--){
            for(int k = 1; k<=2; k++){
                if(k == 2){
                    int c1 = dp[i+1][k-1] - prices[i];
                    int c2 = dp[i+1][k];

                    dp[i][k] = max(c1,c2);
                }
                else{
                    int c1 = dp[i+1][k-1] + prices[i]; 
                    int c2 = dp[i+1][k];

                    dp[i][k] = max(c1,c2);

                }
            }
        }
        return dp[0][2]; // 0 for index  and 2 for k, that's the starting point.
        
    }
};