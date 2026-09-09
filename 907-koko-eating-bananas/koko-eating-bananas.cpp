class Solution {
public:
long long func(vector<int>&arr,int n ,int speed){
    long long h = 0;
    for(int i = 0;i<n;i++){
        h += arr[i]/speed;
        if(arr[i] % speed != 0){
            h++;
        }
        
    }
    return h;
    
}
    int minEatingSpeed(vector<int>& piles, long long h) {
        long long n = piles.size();
        long long low = 1;
        long long high = 0;
        for(int i = 0;i<n;i++){
            high = max(high,(long long)piles[i]);
        }
        long long res = -1;
        while(low<=high){
            long long guess = (low + high)/2;
            long long ans = func(piles,n,guess);
            if(ans > h){
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