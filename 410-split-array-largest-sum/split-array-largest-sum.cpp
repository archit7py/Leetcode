class Solution {
public:
int func(vector<int>&arr,int n, int limit, int k){
    int a = 1;
    int pos = 0;
    for(int i = 0;i<n;i++){
        if(pos + arr[i] <= limit){
            pos += arr[i];
        }
        else{
            a++;
            pos = arr[i];
            if(a>k){
                return false;
            }
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        for(int i = 0;i<n;i++){
            low = max(low,nums[i]);
            high += nums[i];
        }
        int res = -1;
        while(low<=high){
            int guess = (low+high)/2;
            if(func(nums,n,guess,k)){
                res = guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
            
        }
        return res;
        
    }
};