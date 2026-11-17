class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int len = j-i+1;
                for(int d = 1; d<len; d++){
                    if(len%d == 0){
                        int changes = 0;
                        for(int g = 0; g < d; g++) {
                            int left = i+g;
                            int right  = j-((j-i-g)%d);
                            while(left < right){
                                if(s[left] != s[right]){
                                    changes++;
                                }
                                left+=d;
                                right-=d;
                            }
                            

    
                        }
                        cost[i][j] = min(cost[i][j],changes);
                        
                        

                    }

                }
                
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        dp[0][0] = 0;
        for(int parts = 1; parts<=k; parts++){
            for(int i = 2*parts; i<=n; i++){
                for(int p = 2*(parts-1);p<=i-2; p++){
                    if(dp[p][parts-1] != INT_MAX && cost[p][i-1] != INT_MAX) {
                    dp[i][parts] = min(dp[i][parts],dp[p][parts-1] + cost[p][i-1]);
                    }
                    
                     


                }
            }
        }
        return dp[n][k];



        
    }
};