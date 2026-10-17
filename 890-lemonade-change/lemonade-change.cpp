class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for(int i = 0; i<n; i++){
            int money = bills[i];
            if(money == 5){
                five++;
            }
            if(money == 10){
                if(five == 0){
                    return false;
                }
                else{
                    five--;
                    ten++;
                }
                
            }
            if(money == 20){
                if(ten > 0){
                    ten--;
                    if(five == 0){
                        return false;
                    }
                    else{
                        five--;
                    }
                }
                else{
                    if(five < 3){
                        return false;
                    }
                    five -= 3;
                }
            }

        }
        return true;
        
    }
};