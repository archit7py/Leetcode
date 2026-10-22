class NumArray {
    vector<int>res;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        res.resize(n);
        res[0] = nums[0];
        for(int i = 1; i< n; i++){
            res[i] = res[i-1] + nums[i];
        }
       

        
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return res[right];
        }
        return res[right] - res[left-1];
       
        

        
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */