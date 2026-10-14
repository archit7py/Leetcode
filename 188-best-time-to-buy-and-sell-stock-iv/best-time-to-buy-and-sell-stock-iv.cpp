class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1);
        for(int i=0; i<=n; i++){
            vector<int>t(2*k+1);
            dp[i]=t;
        }  
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j<=k*2; j++){
            dp[n][j] = 0;
        } 
        for(int i = n-1; i>=0; i--){
            for(int j = 1; j<=k*2; j++){
                if(j%2 == 0){
                    int c1 = dp[i+1][j-1] - prices[i];
                    int c2 = dp[i+1][j];

                    dp[i][j] =  max(c1,c2);
                }
                else{
                    int c1 = dp[i+1][j-1] + prices[i];
                    int c2 = dp[i+1][j];

                    dp[i][j] =  max(c1,c2);
                }
            }
        }
        return dp[0][2*k];
        
    }
};