class Solution {
public:
    int countCommas(int n) {
        int i = 999;
        if(n<i){
            return 0;
        }
        return n-i ;
    } 

};