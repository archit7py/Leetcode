class Solution {
public:
long long func(vector<int>&a,int n, int speed){
    n = a.size();
    long long h = 0;
    for(int i = 0;i<n;i++){
        h += a[i]/speed;
        if(a[i] % speed != 0){
            h++;
        }
        
    }
    return h;
};
    int minEatingSpeed(vector<int>& piles, int h) {
        long long max = piles[0];
        for(int i = 0;i<piles.size();i++){
            if(piles[i]>max){
                max = piles[i];
            }

        }
        long long low = 1;
        int n = piles.size()-1;
        long high = max;
        long long res = -1;
        while(low<=high){
            int guess = (low + high)/2;
            long long hour = func(piles,n,guess);
            if(hour > h){
                low = guess + 1;
            }
            else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
        
    }
};