class Solution {
public:
bool func(vector<int>&a,long long n, long long limit, long long stud){
           long long k = 1;
           long long page = 0;
           for(int i = 0;i<n;i++){
               if(page + a[i]<=limit){
                   page += a[i];
               }
               else{
                   k++;
                   page = a[i];
                   if(k>stud){
                       return false;
                   }
                }
               
           }
           return true;
       }
    int splitArray(vector<int>& nums, int k) {
        long long n  = nums.size();
        if(n<k){
            return -1;
        }
        long long low = 0;
        long long high = 0;
        for(int i = 0;i<n;i++){
            low = max(low,(long long)nums[i]);
            high += nums[i];
        }
        long long res = -1;
        while(low<=high){
            long long guess = (low+high)/2;
            if(func(nums,n,guess,k)){
                res = guess;
                high = guess - 1;
            }
            else{
                low = guess + 1 ;
            }
        }
        return res;
        
    }
};