class Solution {
public:
int func(int n , int m , int g){
    int row = n-1;
    int col = 0;
    int count = 0;
    for(int i = 1;i<=m;i++){
        count += min(g / i, n);
    }
        
    
    return count;
}

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = n*m;
        int res = -1;
        while(low <= high){
            int g = (low + high)/2;
            int ans = func(n,m,g);
            if(ans<k){
                low = g + 1;

            }
            else{
                res = g;
                high = g - 1;
            }
        }
        return res;
        
    }
};