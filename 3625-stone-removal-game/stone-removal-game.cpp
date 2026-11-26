class Solution {
public:
    bool canAliceWin(int n){
        if(n<10){
            return false;
        }
        bool alice = 1;
        for(int i = 10; i>=1; i--){
            if(n<i){
                break;
            }
            n = n-i;
            alice = 1-alice;
        }
        return alice == 0;

        
        
        


        
        
    }
};