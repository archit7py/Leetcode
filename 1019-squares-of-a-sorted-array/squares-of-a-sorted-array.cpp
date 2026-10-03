class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> a;
        vector<int> b;

        // Separate negative and positive numbers
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }

        // Only positive numbers
        if(a.empty()){
            for(int i = 0; i < b.size(); i++){
                b[i] = b[i] * b[i];
            }
            return b;
        }

        // Only negative numbers
        if(b.empty()){
            for(int i = 0; i < a.size(); i++){
                a[i] = a[i] * a[i];
            }

            reverse(a.begin(), a.end());
            return a;
        }

        // Square negative numbers
        for(int i = 0; i < a.size(); i++){
            a[i] = a[i] * a[i];
        }

        // Reverse because squares of negative numbers
        // are currently in descending order
        reverse(a.begin(), a.end());

        // Square positive numbers
        for(int i = 0; i < b.size(); i++){
            b[i] = b[i] * b[i];
        }

        int c = 0;
        int d = 0;
        int k = 0;

        vector<int> res(a.size() + b.size());

        // Merge two sorted arrays
        while(c < a.size() && d < b.size()){

            if(b[d] < a[c]){
                res[k] = b[d];
                d++;
            }
            else{
                res[k] = a[c];
                c++;
            }

            k++;
        }

        // Remaining elements of a
        while(c < a.size()){
            res[k] = a[c];
            k++;
            c++;
        }

        // Remaining elements of b
        while(d < b.size()){
            res[k] = b[d];
            k++;
            d++;
        }

        return res;
    }
};