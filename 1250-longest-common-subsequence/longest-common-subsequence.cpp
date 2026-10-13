class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int i,j;
        vector<vector<int>>dp(n+1);
        for(int i = 0; i<=n; i++){
            vector<int>t(m+1);
            dp[i] = t;
        }
        //BASE CASE
        for(int i = 0; i<=n; i++){
            dp[i][m] = 0; 
        }
        for(int j = 0; j<=m; j++){
            dp[n][j] = 0;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    int c1 = dp[i+1][j];
                    int c2 = dp[i][j+1];
                    dp[i][j] = max(c1,c2);
                }
            }
        }
        return dp[0][0];

        
    

        
    }
};