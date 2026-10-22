class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>res(n+1,0);
        int sum = 0;
        unordered_map<int,int>f;
        f[0] = 1;
        for(int i = 0; i<n; i++){
            res[i+1] = res[i] + gain[i];
        }

        int a = *max_element(res.begin(), res.end());
        return a;

        
    }
};