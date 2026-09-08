class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int guess = (low + high)/2;
            if(citations[guess] >= n - guess){
                high = guess - 1;
            }
            else{
                low = guess + 1;
            }
            
        }
        return n-low;

        
        
    }
};