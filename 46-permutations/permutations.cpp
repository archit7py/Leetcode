class Solution {
public:
void fun(vector<int>&a,int n, vector<int>&diary, vector<vector<int>>&res,vector<bool>&used ){
    if(diary.size() == n){
        res.push_back(diary);
        return;
    }
    for(int i = 0;i<n;i++){
        if(used[i] == false) {
            used[i] = true;
            diary.push_back(a[i]);
            fun(a,n,diary,res,used);
            diary.pop_back();
            used[i] = false;
            

        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>>res;
        vector<bool>used(n,false);
        vector<int>diary;
        fun(nums,n,diary,res,used);
        return res;
        
    }
};