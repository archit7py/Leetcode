class Solution {
public:
bool func(vector<int>&arr,int n, int limit, int k){
    int days = 1;
    int weight = 0;
    for(int i = 0;i<arr.size();i++){
        if(weight + arr[i] <= limit){
            weight += arr[i];
        }
        else{
            days++;
            weight = arr[i];
            if(days > k){
                return false;
            }
        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
       int n = weights.size();
       int low  = 0;
       int high  = 0;
       
       if(n<days){
        return -1;
       }
       for(int i = 0;i<weights.size();i++){
        low = max(low,weights[i]);
        high += weights[i];
       }
       int res = -1;
       while(low<=high){
            int guess = (low+high)/2;
            if(func(weights,n,guess,days)){
                res = guess;
                high = guess - 1;

            }
            else{
            low = guess + 1;
            }
           
        }
        return res;
        
        
    }
};