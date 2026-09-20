class Solution {
public:
void fun(vector<int>& a , int n, int idx, int sum, vector<int>& diary,vector<vector<int>>& res,int target){
    if(sum == target){
        res.push_back(diary);
        return;
    }

    if(idx == n || sum > target){
        return;
    }
    fun(a,n,idx+1,sum,diary,res,target);
    if(sum + a[idx] <= target){
        diary.push_back(a[idx]);
        sum += a[idx];
        fun(a,n,idx,sum,diary,res,target);
        sum -= a[idx];
        diary.pop_back();
    }
    return;
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        int n = candidates.size();
        vector<int> diary;
        vector<vector<int>> res;
        int idx = 0;
        fun(candidates, n, idx,sum,diary,res,target);
        return res;
        
        
    }
};