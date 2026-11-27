class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>dp(budget + 1, 0);
        int mini = INT_MAX;
        for(int i = 0; i<items.size(); i++){
            int price = items[i][1];
            mini = min(mini,price);
            int count  = 1;
            for(int j = 0; j<items.size(); j++){
                if(i != j && items[j][0]%items[i][0] == 0){
                    count++;
                }
            }
            for(int j = budget; j>= price; j--){
                dp[j] = max(dp[j],dp[j-price]+count);
            }

            
        }
        int ans = 0;
        for(int i = 0; i<=budget; i++){
            int left = budget - i;
            ans = max(ans,dp[i] + left/mini);
        }
        return ans;
        
    }
};