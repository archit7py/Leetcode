class Solution {
public:

    void fun(vector<int>& a, int n, int idx, vector<int> diary,
             vector<vector<int>>& res, int sum, int target,
             vector<bool>& used) {

        if(sum == target){
            res.push_back(diary);
            return;
        }

        if(idx == n || sum > target){
            return;
        }

        // NOT PICK
        int next = idx + 1;

        while(next < n && a[next] == a[idx]){
            next++;
        }

        fun(a, n, next, diary, res, sum, target, used);


        // PICK
        if(sum + a[idx] <= target){

            if(used[idx] == false){

                used[idx] = true;

                diary.push_back(a[idx]);
                sum += a[idx];

                fun(a, n, idx + 1, diary, res, sum, target, used);

                sum -= a[idx];
                diary.pop_back();

                used[idx] = false;
            }
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int n = candidates.size();

        sort(candidates.begin(), candidates.end());

        vector<int> diary;
        vector<vector<int>> res;
        vector<bool> used(n, false);

        fun(candidates, n, 0, diary, res, 0, target, used);

        return res;
    }
};