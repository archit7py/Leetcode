class Solution {
public:
    int climbStairs(int n) {
        int i = 0;
        if (i == n){
            return 1;
        }
        if(i > n){
            return 0;
        }
        int ahead = 0;
        int ahead_ahead = 1;
        for(int i = 0; i<n; i++){
            int ans = ahead + ahead_ahead;
            ahead = ahead_ahead;
            ahead_ahead = ans;
        }
        return ahead_ahead;
        
    }
};