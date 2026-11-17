typedef long long int ll;
class Solution {
public:
    

int check(string b){
        int n = b.size();
        int sum = 0 ;
        for(ll i=0;i<n/2;i++){
            if(b[i]!=b[n-i-1]){
                sum = sum + 1;
            }
        }
        return sum;
    }

    int cl(vector <string> & S){
        int answer = 0 ;
        for(ll i=0;i<S.size();i++){
            answer = answer + check(S[i]);
        }
        return answer;
    }

    int minimumChanges(string s, int K) {
        // Pre-computation of Divisor
        ll n = s.size();
        vector <ll> G[n+1];
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=i-1;j++){
                if(i%j==0){
                    G[i].push_back(j);
                }
            }
        }

        //Cost Calculation
        vector<vector<int>> cost(n, vector<int>(n,1e8));


        for(ll i=0;i<=n-1;i++){
            for(ll j=i;j<=n-1;j++){
                //[i....j]
                ll l = j-i+1;
               
                for(auto u : G[l]){
                    vector <string> S(u,"");
                    ll id = 0;
                    for(ll p=i;p<=j;p++){
                        ll v = id%u;
                        S[v].push_back(s[p]);
                        id++;
                    }
                    int op = S.size();
                   
                    cost[i][j] = min(cost[i][j],cl(S));  
                }
               
            }
        }

        vector<vector<int>> dp(n, vector<int>(K+1,1e8));
        dp[0][1] = 1e8;
        for(ll i=1;i<=n-1;i++){
            dp[i][1] = cost[0][i];  
            for(ll k=2;k<=K;k++){
                for(ll j=i;j>=1;j--){
                    dp[i][k] = min(dp[i][k],cost[j][i]+dp[j-1][k-1]);
                }
            }
        }

        return dp[n-1][K];

       
        
        
    }
};